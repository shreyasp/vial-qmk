# Properly enable SPI and EEPROM
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = spi_flash

# Disable unused features to save space
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = yes
GRAVE_ESC_ENABLE = yes
MAGIC_ENABLE = yes
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
EXTRAKEY_ENABLE = yes

# Enable additional features
KEY_OVERRIDE_ENABLE = yes

# Enable modifiers based on Mac layout
APPLE_FN_ENABLE = yes

# Optimize firmware size
LTO_ENABLE = yes
EXTRAFLAGS += -flto
