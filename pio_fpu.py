# Aplica as flags de FPU (hard float, como no STM32CubeIDE) na compilacao,
# no assembler e no linker, e usa newlib-nano (syscalls.c/sysmem.c do projeto).
Import("env")

fpu = ["-mfpu=fpv4-sp-d16", "-mfloat-abi=hard"]

env.Append(
    CCFLAGS=fpu,
    ASFLAGS=fpu,
    ASPPFLAGS=fpu,
    # -fno-use-linker-plugin: evita carregar liblto_plugin.dll (falha em
    # alguns Windows); o projeto nao usa LTO.
    LINKFLAGS=fpu + ["--specs=nano.specs", "-Wl,--gc-sections",
                     "-fno-use-linker-plugin"],
)
