# Properly enable SPI and EEPROM
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = spi_flash

# Disable unused features to save space
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# Enable additional features
KEY_OVERRIDE_ENABLE = yes

# Enable modifiers based on Mac layout
APPLE_FN_ENABLE = yes

# Optimize firmware size
LTO_ENABLE = yes
EXTRAFLAGS += -flto
