clean_man:
	@$(RMRF) $(DIR_OBJ)/$(MAN)

clean_bon:
	@$(RMRF) $(DIR_OBJ)/$(BONUS)

clean:
	@$(RMRF) $(DIR_OBJ)

fclean_man:	clean_man
	@$(RM) ./bin/$(NAME)

fclean_bon:	clean_bon
	@$(RM) ./bin/$(NAME_BNS)

fclean:		clean fclean_man fclean_bon

re:			fclean all

re_man:		fclean_man all

re_bon:		fclean_bon bonus

norm:
	norminette

help:
	@$(PRT) "Usage: make [$(Y)target$(O)]"
	@$(PRT) ""
	@$(PRT) "Available targets:"
	@$(PRT) "$(Y)help          $(V)Show this help message"
	@$(PRT) "$(Y)all           $(V)Build the project (default target)"
	@$(PRT) "$(Y)bonus         $(V)Build the bonus project (bonus target)"
	@$(PRT) "$(Y)clean         $(V)Remove object folder and files"
	@$(PRT) "$(Y)clean_man     $(V)Remove object mandatory files"
	@$(PRT) "$(Y)clean_bonus   $(V)Remove object bonus files"
	@$(PRT) "$(Y)fclean        $(V)Remove object files and executables"
	@$(PRT) "$(Y)fclean_man    $(V)Remove object mandatory files and executable 'philo'"
	@$(PRT) "$(Y)fclean_bonus  $(V)Remove object bonus files and executable 'philo_bonus'"
	@$(PRT) "$(Y)re            $(V)Clean and rebuild the project (equivalent to fclean + all)"
	@$(PRT) "$(Y)re_man        $(V)Clean and rebuild the project (equivalent to fclean_man + all)"
	@$(PRT) "$(Y)re_bonus      $(V)Clean and rebuild the project (equivalent to fclean_bonus + bonus)"
	@$(PRT) "$(Y)norm          $(V)Run norminette"
# 	@$(PRT) "$(Y)debug         $(V)Build with debug flags"
	@$(PRT) ""
	@$(PRT) "$(Y)Examples:"  
	@$(PRT) "$(Y)make          $(V)# Build the project"
	@$(PRT) "$(Y)make clean    $(V)# Remove temporary files"
	@$(PRT) "$(Y)make re       $(V)# Clean rebuild"
	@$(PRT) "$(Y)make help     $(V)# Show this help$(O)"
	@$(PRT) ""
	@$(PRT) "For more information, see the project documentation."
