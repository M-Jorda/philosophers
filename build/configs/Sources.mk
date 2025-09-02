# ******************************** MANDATORY ********************************* #

MAN			= src/philo/

# 						---------  CLEANUP  ---------						   #
CLEANUP		= $(MAN)cleanup/
CLEANUP_SRC	= $(CLEANUP)cleanup.c $(CLEANUP)mutexes.c $(CLEANUP)philos.c

#						---------   CORE    ---------						   #
CORE		= $(MAN)core/
CORE_SRC	= $(CORE)main.c $(CORE)philo.c $(CORE)monitoring.c $(CORE)forks.c

#						---------   INIT	---------						   #
INIT		= $(MAN)init/
INIT_SRC	= $(INIT)init.c $(INIT)mutexes.c $(INIT)philos.c

# 						---------   UTILS	---------						   #
UTILS		= $(MAN)utils/
UTILS_SRC	= $(UTILS)utils.c $(UTILS)err.c $(UTILS)print.c

# 						---------   DEBUG   ---------						   #
DEBUG		= $(MAN)debug/
DEBUG_SRC	= $(DEBUG)debug.c

# 						---------  SOURCES  ---------						   #
MAN_SRC		= $(CORE_SRC) $(INIT_SRC) $(UTILS_SRC) $(CLEANUP_SRC) $(DEBUG_SRC)

# ********************************* OBJECTS ********************************** #

DIR_OBJ		= objects
DIR			= $(DIR_OBJ)/
OBJ			= $(patsubst %.c, $(DIR)%.o, $(MAN_SRC))
