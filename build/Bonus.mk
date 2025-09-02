bonus:	$(NAME_BNS)

dir_bonus:
	@mkdir -p $(DIR_OBJ)

$(NAME_BNS):	$(OBJ)
	@$(CC) $(CFLAGS) -o ./output/$@ $(OBJ)
	@$(PRINT) $(BANNER_BNS)

$(DIR)%.o: %.c | dir_bonus
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"