all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@$(PRINT) $(BANNER)

dir_mandatory:
	

$(DIR)%.o: %.c | dir_mandatory
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"