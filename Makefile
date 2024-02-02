# Created by Matthew Boyea on 2024-01-23
# Last Edited by Matthew Boyea on 2024-01-25

# file extensions
SRC_EXT := cpp
INC_EXT := h
OBJ_EXT := o
RC_EXT := rc
# DLL_EXT := dll
EXE_EXT := exe

# project directories
SRC_DIR := src
OBJ_DIR := build
TARGET_DIR := bin
# STATIC_DIR := static

# libs & flags
# LIB_DIR := lib
# LIB_INC_DIRS := $(shell find $(LIB_DIR) -type d -path "*/include")
# LIB_LIB_DIRS := $(shell find $(LIB_DIR) -type d -path "*/lib")
# LIB_DLL_DIRS := $(shell find $(LIB_DIR) -type d -path "*/bin")

# cross-platform compilers & flags
CXX := g++
CXXFLAGS := -std=c++17 -g# -Wall
LDFLAGS := $(addprefix -L,$(LIB_LIB_DIRS))
LDLIBS := $(addprefix -l,)

# target files
EXE_NAME := Output
EXE_PATH := $(TARGET_DIR)/$(EXE_NAME)
SRCS := $(shell find $(SRC_DIR) -type f -name "*.$(SRC_EXT)")
OBJS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.$(SRC_EXT)=.$(OBJ_EXT)))
RCS := $(shell find $(SRC_DIR) -type f -name "*.$(RC_EXT)")
OBJS := $(OBJS) $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(RCS:.$(RC_EXT)=.$(OBJ_EXT)))
# LIB_DLLS := $(shell find $(LIB_DLL_DIRS) -type f -name "*.$(DLL_EXT)")
# DLLS := $(addprefix $(TARGET_DIR)/,$(notdir $(LIB_DLLS)))
# STATICS := $(patsubst $(STATIC_DIR)/%,$(TARGET_DIR)/%,$(shell find $(STATIC_DIR) -type f -name "*"))

all : $(EXE_PATH).$(EXE_EXT) $(DLLS) $(STATICS)

# $(TARGET_DIR)/%: $(STATIC_DIR)/%
# 	@mkdir -p $(TARGET_DIR)
# 	@echo "Copying $< into $@..."; install -D "$<" "$@"

# define COPY_DLL_template
# $(TARGET_DIR)/%.$(DLL_EXT) : $(1)/%.$(DLL_EXT)
# 	@mkdir -p $(TARGET_DIR)
# 	@echo "Copying $$(<) into $$(@) ..."; cp "$$(<)" "$$(@)"
# endef
# $(foreach LIB_DLL_DIR,$(LIB_DLL_DIRS),$(eval $(call COPY_DLL_template,$(LIB_DLL_DIR))))

$(EXE_PATH).$(EXE_EXT) : $(OBJS)
	@mkdir -p $(TARGET_DIR)
	@echo "Linking..."; $(CXX) $^ $(LDFLAGS) $(LDLIBS) -o $(EXE_PATH)

$(OBJ_DIR)/%.$(OBJ_EXT) : $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."; $(CXX) $(CXXFLAGS) $(addprefix -I,$(LIB_INC_DIRS)) -c -o $@ $<

$(OBJ_DIR)/%.$(OBJ_EXT) : $(SRC_DIR)/%.$(RC_EXT)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."; windres $< $@

clean :
	@echo "Cleaning..."; $(RM) -r $(OBJ_DIR) $(TARGET_DIR)

.PHONY : all run clean

