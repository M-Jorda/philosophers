bonus:	$(NAME_BNS)

$(NAME_BNS):	$(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@$(PRINT) $(BANNER_BNS)

dir_bonus:
	

$(DIR)%.o: %.c | dir_bonus
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"