TARGET=BasicFunctionsForward2

SRCS=$(TARGET).cpp 

CUSRCS=

INCLUDES=-I.. -I../../vsgraph/Public -I../../vsgraph/linux -I../../vsgraph/Private -I../BasicFunctions

-include ../../Executable.mk

LIBPATH=../../vsgraph/$(LIBDIR)
LIBPATH_SHARED=$(LIBPATH)/shared
LIBPATH_STATIC=$(LIBPATH)/static

$(DEBUG_DIR)/$(TARGET)_static: $(debug_OBJS) $(LIBPATH_STATIC)/libvsgraph.a
	$(NVCC) -o $(DEBUG_DIR)/$(TARGET)_static $(debug_OBJS) -L$(LIBPATH_STATIC) -lvsgraph -lcppunit -lz -lboost_iostreams -lcudart_static

$(DEBUG_DIR)/$(TARGET): $(debug_OBJS) $(LIBPATH_SHARED)/libvsgraph.so
	$(CC) -o $(DEBUG_DIR)/$(TARGET) $(debug_OBJS) -L$(LIBPATH_SHARED) -lvsgraph -lcppunit

debug: $(DEBUG_DIR)/$(TARGET)_static $(DEBUG_DIR)/$(TARGET)

$(RELEASE_DIR)/$(TARGET)_static: $(release_OBJS) $(LIBPATH_STATIC)/libvsgraph.a
	$(NVCC) -o $(RELEASE_DIR)/$(TARGET)_static $(release_OBJS) -L$(LIBPATH_STATIC) -lvsgraph -lcppunit -lz -lboost_iostreams -lcudart_static

$(RELEASE_DIR)/$(TARGET): $(release_OBJS) $(LIBPATH_SHARED)/libvsgraph.so
	$(CC) -o $(RELEASE_DIR)/$(TARGET) $(release_OBJS) -L$(LIBPATH_SHARED) -lvsgraph -lcppunit


release: $(RELEASE_DIR)/$(TARGET)_static $(RELEASE_DIR)/$(TARGET)

test_debug: 
	$(MAKE) debug
	LD_LIBRARY_PATH=$(LIBPATH_SHARED) $(DEBUG_DIR)/$(TARGET)
	$(DEBUG_DIR)/$(TARGET)_static

test_release: 
	$(MAKE) release
	LD_LIBRARY_PATH=$(LIBPATH_SHARED) $(RELEASE_DIR)/$(TARGET)
	$(RELEASE_DIR)/$(TARGET)_static



