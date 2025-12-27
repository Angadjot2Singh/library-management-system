CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = library_system
OBJDIR = obj
SRCDIR = .
DATADIR = data

SOURCES = User.cpp Book.cpp Circulation.cpp Fine.cpp Library.cpp main.cpp
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(DATADIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✓ Build successful! Executable: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "✓ Compiled: $<"

clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "✓ Clean complete!"

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

help:
	@echo "Available targets:"
	@echo "  make           - Build the project"
	@echo "  make run       - Build and run the program"
	@echo "  make clean     - Remove build artifacts"
	@echo "  make rebuild   - Clean and rebuild"
	@echo "  make help      - Display this help message"

.PHONY: all clean run rebuild help