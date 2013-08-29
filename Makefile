SUBDIRS = lib testmodule server client

BUILDSUBDIRS = $(SUBDIRS:%=build-%)

CLEANSUBDIRS = $(SUBDIRS:%=clean-%)

all: $(BUILDSUBDIRS)

$(BUILDSUBDIRS):
	$(MAKE) -C $(@:build-%=%)

clean: $(CLEANSUBDIRS)

$(CLEANSUBDIRS):
	$(MAKE) -C $(@:clean-%=%) clean

.PHONY: $(SUBDIRS) $(BUILDSUBDIRS) $(CLEANSUBDIRS) all clean
