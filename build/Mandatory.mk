all:	$(NAME)

dir_mandatory:
	@mkdir -p $(DIR_OBJ)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o ./output/$(NAME) $(OBJ)
	@$(PRINT) $(BANNER)	

$(DIR)%.o: %.c | dir_mandatory
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"
