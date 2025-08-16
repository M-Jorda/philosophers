# ******************************** MANDATORY ********************************* #

MAN			= philo/

#						---------   SETUP	---------						   #
SUP			= $(MAN)setup/
SUP_SRC		= $(SUP)init.c $(SUP)mutexes.c $(SUP)philo.c

# 						---------   UTILS	---------						   #
UTI_SRC		= $(MAN)utils.c

# 						---------  CLEANUP  ---------						   #
CUP			= $(MAN)cleanup/
CUP_SRC		= $(CUP)cleanup.c

# 						---------  SOURCES  ---------						   #
MAN_SRC		= $(MAN)main.c $(SUP_SRC) $(UTI_SRC) $(CUP_SRC)


# ********************************* OBJECTS ********************************** #

DIR_OBJ		= obj
DIR			= $(DIR_OBJ)/
OBJ			= $(patsubst %.c, $(DIR)%.p, $(MAN_SRC))
