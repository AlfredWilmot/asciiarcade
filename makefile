#Set this to @ to keep the makefile quiet
SILENCE = @

# Coloroze output
CPPUTEST_EXE_FLAGS += -c

#---- Outputs ----#
COMPONENT_NAME = your

#--- Inputs ----#
PROJECT_HOME_DIR = .
ifeq "$(CPPUTEST_HOME)" ""
$(error The environment variable CPPUTEST_HOME is not set. \
Set it to where cpputest is installed)
endif

# INCLUDE_DIRS are searched in order after the included file's
# containing directory
INCLUDE_DIRS += $(CPPUTEST_HOME)/include
INCLUDE_DIRS += $(CPPUTEST_HOME)/include/Platforms/Gcc

SRC_DIRS = \
	src

TEST_SRC_DIRS = \
	tests

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

# References:
# > https://github.com/jwgrenning/cpputest-starter-project/blob/master/makefile
