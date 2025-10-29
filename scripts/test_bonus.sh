#!/bin/bash

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

PHILO="./output/philo_bonus"
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

print_test_header() {
    echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${BLUE}Test $1: $2${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
}

print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✅ PASS${NC}: $2"
        ((PASSED_TESTS++))
    else
        echo -e "${RED}❌ FAIL${NC}: $2"
        ((FAILED_TESTS++))
    fi
    ((TOTAL_TESTS++))
}

check_death_time() {
    local output="$1"
    local expected_time=$2
    local tolerance=$3
    
    # Extraire le timestamp de la mort
    local death_line=$(echo "$output" | grep "died")
    if [ -z "$death_line" ]; then
        return 1
    fi
    
    local death_time=$(echo "$death_line" | awk '{print $1}')
    
    # Vérifier si le temps est dans la tolérance
    local min_time=$((expected_time - tolerance))
    local max_time=$((expected_time + tolerance))
    
    if [ "$death_time" -ge "$min_time" ] && [ "$death_time" -le "$max_time" ]; then
        return 0
    else
        echo "    Death at ${death_time}ms (expected ~${expected_time}ms ±${tolerance}ms)"
        return 1
    fi
}

# ============================================================================
# TEST 1: 1 philo doit mourir à 200ms
# ============================================================================
print_test_header "1" "./philo 1 200 200 200"
echo "Expected: Philo 1 takes one fork and dies at ~200ms"

OUTPUT=$(timeout 1 $PHILO 1 200 200 200 2>&1)
if echo "$OUTPUT" | grep -q "has taken a fork" && echo "$OUTPUT" | grep -q "died"; then
    if check_death_time "$OUTPUT" 200 10; then
        print_result 0 "Philo died at correct time"
    else
        print_result 1 "Philo died but timing is wrong"
    fi
else
    print_result 1 "Expected death not found"
    echo "$OUTPUT" | head -5
fi

# ============================================================================
# TEST 2: 2 philos, personne ne meurt
# ============================================================================
print_test_header "2" "./philo 2 800 200 200"
echo "Expected: No deaths"

OUTPUT=$(timeout 3 $PHILO 2 800 200 200 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    print_result 1 "Unexpected death detected"
    echo "$OUTPUT" | grep "died"
else
    print_result 0 "No deaths (as expected)"
fi

# ============================================================================
# TEST 3: 5 philos, personne ne meurt
# ============================================================================
print_test_header "3" "./philo 5 800 200 200"
echo "Expected: No deaths"

OUTPUT=$(timeout 3 $PHILO 5 800 200 200 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    print_result 1 "Unexpected death detected"
    echo "$OUTPUT" | grep "died"
else
    print_result 0 "No deaths (as expected)"
fi

# ============================================================================
# TEST 4: 5 philos avec must_eat=7
# ============================================================================
print_test_header "4" "./philo 5 800 200 200 7"
echo "Expected: Simulation stops when each philo ate 7 times"

timeout 10 $PHILO 5 800 200 200 7 > /tmp/philo_test4.txt 2>&1
EXIT_CODE=$?

if [ $EXIT_CODE -eq 0 ]; then
    # Vérifier qu'il n'y a pas de mort
    if grep -q "died" /tmp/philo_test4.txt; then
        print_result 1 "Death detected (should stop before death)"
    else
        print_result 0 "Simulation ended correctly"
    fi
else
    print_result 1 "Simulation did not end naturally (timeout or error)"
fi

# ============================================================================
# TEST 5: 4 philos, 410ms to die, personne ne meurt
# ============================================================================
print_test_header "5" "./philo 4 410 200 200"
echo "Expected: No deaths"

OUTPUT=$(timeout 3 $PHILO 4 410 200 200 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    print_result 1 "Unexpected death detected"
    echo "$OUTPUT" | grep "died"
else
    print_result 0 "No deaths (as expected)"
fi

# ============================================================================
# TEST 6: 4 philos, 310ms to die, un philo meurt
# ============================================================================
print_test_header "6" "./philo 4 310 200 200"
echo "Expected: One philo dies"

OUTPUT=$(timeout 2 $PHILO 4 310 200 200 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    print_result 0 "Death detected (as expected)"
    echo "$OUTPUT" | grep "died"
else
    print_result 1 "No death detected (expected a death)"
fi

# ============================================================================
# TEST 7: Argument invalide (float 1.2)
# ============================================================================
print_test_header "7" "./philo 4 500 200 1.2"
echo "Expected: Invalid argument error"

OUTPUT=$(timeout 2 $PHILO 4 500 200 1.2 2>&1)
EXIT_CODE=$?

if [ $EXIT_CODE -ne 0 ] || echo "$OUTPUT" | grep -qi "error\|invalid\|usage"; then
    print_result 0 "Invalid argument rejected"
else
    print_result 1 "Invalid argument accepted (should be rejected)"
fi

# ============================================================================
# TEST 8: Argument invalide (0)
# ============================================================================
print_test_header "8" "./philo 4 0 200 200"
echo "Expected: Invalid argument error"

OUTPUT=$(timeout 2 $PHILO 4 0 200 200 2>&1)
EXIT_CODE=$?

if [ $EXIT_CODE -ne 0 ] || echo "$OUTPUT" | grep -qi "error\|invalid\|usage"; then
    print_result 0 "Zero argument rejected"
else
    print_result 1 "Zero argument accepted (should be rejected)"
fi

# ============================================================================
# TEST 9: Argument invalide (négatif)
# ============================================================================
print_test_header "9" "./philo 4 -500 200 200"
echo "Expected: Invalid argument error"

OUTPUT=$(timeout 2 $PHILO 4 -500 200 200 2>&1)
EXIT_CODE=$?

if [ $EXIT_CODE -ne 0 ] || echo "$OUTPUT" | grep -qi "error\|invalid\|usage"; then
    print_result 0 "Negative argument rejected"
else
    print_result 1 "Negative argument accepted (should be rejected)"
fi

# ============================================================================
# TEST 10: time_to_sleep = INT_MAX, un philo meurt à 500ms
# ============================================================================
print_test_header "10" "./philo 4 500 200 2147483647"
echo "Expected: One philo dies at ~500ms"

OUTPUT=$(timeout 2 $PHILO 4 500 200 2147483647 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    if check_death_time "$OUTPUT" 500 50; then
        print_result 0 "Death at correct time with INT_MAX sleep"
    else
        print_result 1 "Death detected but timing wrong"
    fi
else
    print_result 1 "No death detected (expected death at ~500ms)"
fi

# ============================================================================
# TEST 11: time_to_die = INT_MAX, personne ne meurt
# ============================================================================
print_test_header "11" "./philo 4 2147483647 200 200"
echo "Expected: No deaths"

OUTPUT=$(timeout 10 $PHILO 4 2147483647 200 200 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    print_result 1 "Unexpected death with INT_MAX time_to_die"
else
    print_result 0 "No deaths with INT_MAX (as expected)"
fi

# ============================================================================
# TEST 12: Argument > INT_MAX (overflow)
# ============================================================================
print_test_header "12" "./philo 4 214748364732 200 200"
echo "Expected: Invalid argument error (overflow)"

OUTPUT=$(timeout 2 $PHILO 4 214748364732 200 200 2>&1)
EXIT_CODE=$?

if [ $EXIT_CODE -ne 0 ] || echo "$OUTPUT" | grep -qi "error\|invalid\|usage"; then
    print_result 0 "Overflow rejected"
else
    print_result 1 "Overflow accepted (should be rejected)"
fi

# ============================================================================
# TEST 13: Mort affichée en < 10ms (4 200 210 200)
# ============================================================================
print_test_header "13" "./philo 4 200 210 200"
echo "Expected: Death displayed within 10ms of occurrence (before 210ms)"

OUTPUT=$(timeout 1 $PHILO 4 200 210 200 2>&1)
if echo "$OUTPUT" | grep -q "died"; then
    DEATH_LINE=$(echo "$OUTPUT" | grep "died" | head -1)
    DEATH_TIME=$(echo "$DEATH_LINE" | awk '{print $1}')
    
    if [ "$DEATH_TIME" -lt 210 ]; then
        print_result 0 "Death displayed at ${DEATH_TIME}ms (< 210ms)"
    else
        print_result 1 "Death displayed at ${DEATH_TIME}ms (should be < 210ms)"
    fi
else
    print_result 1 "No death detected"
fi

# ============================================================================
# RÉSUMÉ FINAL
# ============================================================================
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${BLUE}                        RÉSUMÉ FINAL                           ${NC}"
echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

PASS_RATE=$((PASSED_TESTS * 100 / TOTAL_TESTS))

echo -e "\nTotal tests: ${TOTAL_TESTS}"
echo -e "${GREEN}Passed: ${PASSED_TESTS}${NC}"
echo -e "${RED}Failed: ${FAILED_TESTS}${NC}"
echo -e "Success rate: ${PASS_RATE}%"

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "\n${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}\n"
    exit 0
else
    echo -e "\n${RED}⚠️  SOME TESTS FAILED ⚠️${NC}\n"
    exit 1
fi
