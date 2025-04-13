NAME = main

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and build directories
SRC_DIR = .
BUILD_DIR = build

# Source files (add more files here later)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object and dependency files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Default rule
all: $(NAME)

# Link object files into final binary
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o inside build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $@

# Clean object and dependency files
clean:
	rm -rf $(BUILD_DIR)

# Clean everything including the binary
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
