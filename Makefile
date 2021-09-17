# Sound enhancer custom MAKEFILE -> Main function call
define MAIN
	./core $(1) $(2) $(3)
endef

# Prompt Make 'sound' (accepting 3 command-line arguments)
sound:
	$(call MAIN, $(in) $(out) $(f))