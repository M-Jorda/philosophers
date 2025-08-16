clean:
	@$(RM) $(DIR_OBJ)

clean_man:
	@$(RM) $(DIR_OBJ)/$(MAN)

clean_bon:
	@$(RM) $(DIR_OBJ)/$(BONUS)

fclean:		clean
	@$(RM) $(NAME) $(NAME_BONUS)

fclean_man:	clean_man
	@$(RM) $(NAME)

fclean_bon:	clean_bon
	@$(RM) $(NAME_BONUS)

re:			fclean all

re_man:		fclean_man all

re_bon:		fclean_bon bonus

help:
	@$(PRT)"Usage: make [target]"
	@$(PRT)""
	@$(PRT)"Available targets:"
	@$(PRT)"help         Show this help message"
	@$(PRT)"all          Build the project (default target)"
	@$(PRT)"bonus        Build the bonus project (bonus target)"
	@$(PRT)"clean        Remove object files and temporary files"
	@$(PRT)"clean_man    Remove object files and temporary files"
	@$(PRT)"clean_bonus  Remove object files and temporary files"
	@$(PRT)"fclean       Remove object files and executable/library"
	@$(PRT)"fclean_man   Remove object files and executable/library"
	@$(PRT)"fclean_bonus Remove object files and executable/library"
	@$(PRT)"re           Clean and rebuild the project (equivalent to fclean + all)"
	@$(PRT)"re_man       Clean and rebuild the project (equivalent to fclean + all)"
	@$(PRT)"re_bonus     Clean and rebuild the project (equivalent to fclean + all)"
	@$(PRT)"norm         Run norminette"
# 	@$(PRT)"debug        Build with debug flags"
	@$(PRT)""
	@$(PRT)"Examples:" 
	@$(PRT)"make         # Build the project"
	@$(PRT)"make clean   # Remove temporary files"
	@$(PRT)"make re      # Clean rebuild"
	@$(PRT)"make help    # Show this help"
	@$(PRT)""
	@$(PRT)"For more information, see the project documentation."
