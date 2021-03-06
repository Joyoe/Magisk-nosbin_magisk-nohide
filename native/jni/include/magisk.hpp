#pragma once

#include <string>

#define MAIN_SOCKET  "d30138f2310a9fb9c54a3e0c21f58591"
#define JAVA_PACKAGE_NAME "com.brightsight.joker"
#define LOGFILE         "/cache/magisk.log"
#define UNBLOCKFILE     "/dev/.magisk_unblock"
#define SECURE_DIR      "/data/adb"
#define MODULEROOT      SECURE_DIR "/modules"
#define MODULEUPGRADE   SECURE_DIR "/modules_update"
#define DATABIN         SECURE_DIR "/magisk"
#define JOKERDB        SECURE_DIR "/magisk.db"
#define MANAGERAPK      DATABIN "/magisk.apk"

// tmpfs paths
extern std::string  JOKERTMP;
#define INTLROOT    ".magisk"
#define MIRRDIR     INTLROOT "/mirror"
#define RULESDIR    MIRRDIR "/sepolicy.rules"
#define BLOCKDIR    INTLROOT "/block"
#define MODULEMNT   INTLROOT "/modules"
#define BBPATH      INTLROOT "/busybox"
#define ROOTOVL     INTLROOT "/rootdir"
#define ROOTMNT     ROOTOVL "/.mount_list"

constexpr const char *applet_names[] = { "jojo", "josetprop", "magiskhide", nullptr };
constexpr const char *init_applet[] = { "joiskpolicy", "jojopolicy", nullptr };

#define POST_FS_DATA_WAIT_TIME       40
#define POST_FS_DATA_SCRIPT_MAX_TIME 35

extern int SDK_INT;
#define APP_DATA_DIR (SDK_INT >= 24 ? "/data/user_de" : "/data/user")

// Multi-call entrypoints
int magisk_main(int argc, char *argv[]);
int magiskhide_main(int argc, char *argv[]);
int magiskpolicy_main(int argc, char *argv[]);
int su_client_main(int argc, char *argv[]);
int resetprop_main(int argc, char *argv[]);
int app_process_main(int argc, char *argv[]);
