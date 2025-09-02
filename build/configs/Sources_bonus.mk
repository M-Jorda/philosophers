# ********************************** BONUS *********************************** #

BNS_DIR		= src/philo_bonus/

# 						---------  CLEANUP  ---------						   #
CLEANUP		= $(BNS_DIR)cleanup/
CLEANUP_SRC	= $(CLEANUP)cleanup_bonus.c

#						---------   CORE    ---------						   #
CORE		= $(BNS_DIR)core/
CORE_SRC	= $(CORE)main.c $(CORE)philo_bonus.c $(CORE)monitoring_bonus.c $(CORE)forks_bonus.c

#						---------   INIT	---------						   #
INIT		= $(BNS_DIR)init/
INIT_SRC	= $(INIT)init_bonus.c $(INIT)sem_bonus.c $(INIT)philo_bonus.c

# 						---------   UTILS	---------						   #
UTILS		= $(BNS_DIR)utils/
UTILS_SRC	= $(UTILS)utils_bonus.c $(UTILS)err_bonus.c $(UTILS)print_bonus.c

# 						---------  SOURCES  ---------						   #
BNS_SRC		= $(CORE_SRC) $(INIT_SRC) $(UTILS_SRC) $(CLEANUP_SRC)

# ********************************* OBJECTS ********************************** #

DIR_OBJ		= objects
DIR			= $(DIR_OBJ)/
OBJ			= $(patsubst %.c, $(DIR)%.o, $(BNS_SRC))