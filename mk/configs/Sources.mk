# ********************************* BONUS *********************************** #

MAN			= philo/
SRC			= $(MAN)main.c

# ********************************* BONUS *********************************** #

BNS_DIR		= philo_bonus/
BNS_C		= _bonus.c
BNS_SRC		= $(BNS_DIR)main.c

# ********************************* OBJECTS ********************************** #

DIR_OBJ		= obj
DIR			= $(DIR_OBJ)/
OBJ			= $(patsubst %.c, $(DIR)%.p, $(SRC))