all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o ./bin/$(NAME) $(OBJ)
	@$(PRINT) $(BANNER)	

$(DIR)%.o: %.c | dir_mandatory
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"
