# ******************************** MANDATORY ********************************* #

MAN			= philo/

#						---------   SETUP	---------						   #
SUP			= $(MAN)setup/
SUP_SRC		= $(SUP)init.c $(SUP)mutexes.c $(SUP)philos.c

# 						---------   UTILS	---------						   #
UTI_SRC		= $(MAN)utils.c

# 						---------  CLEANUP  ---------						   #
CUP			= $(MAN)cleanup/
CUP_SRC		= $(CUP)cleanup.c $(CUP)mutexes.c $(CUP)philos.c

# 						---------  SOURCES  ---------						   #
MAN_SRC		= $(MAN)main.c $(MAN)philo.c $(MAN)monitoring.c $(MAN)err.c		\
	$(MAN)utils.c $(SUP_SRC) $(UTI_SRC) $(CUP_SRC)

# ********************************* OBJECTS ********************************** #

DIR_OBJ		= obj
DIR			= $(DIR_OBJ)/
OBJ			= $(patsubst %.c, $(DIR)%.o, $(MAN_SRC))
