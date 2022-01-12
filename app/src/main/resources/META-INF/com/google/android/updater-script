#JOKER
############################################
# Magisk Flash Script (updater-script)
############################################

##############
# Preparation
##############

# Default permissions
umask 022

OUTFD=$2
APK="$3"
COMMONDIR=$INSTALLER/assets
CHROMEDIR=$INSTALLER/assets/chromeos

if [ ! -f $COMMONDIR/util_functions.sh ]; then
  echo "! Unable to extract zip file!"
  exit 1
fi

# Load utility functions
. $COMMONDIR/util_functions.sh

setup_flashable

############
# Detection
############

if echo $JOKER_VER | grep -q '\.'; then
  PRETTY_VER=$JOKER_VER
else
  PRETTY_VER="$JOKER_VER($JOKER_VER_CODE)"
fi
print_title "Magisk $PRETTY_VER Installer"

is_mounted /data || mount /data || is_mounted /cache || mount /cache
mount_partitions
check_data
get_flags
find_boot_image

[ -z $BOOTIMAGE ] && abort "! Unable to detect target image"
ui_print "- Target image: $BOOTIMAGE"

# Detect version and architecture
api_level_arch_detect

[ $API -lt 21 ] && abort "! Magisk only support Android 5.0 and above"

ui_print "- Device platform: $ABI"

BINDIR=$INSTALLER/lib/$ABI
cd $BINDIR
for file in lib*.so; do mv "$file" "${file:3:${#file}-6}"; done
cd /
cp -af $INSTALLER/lib/$ABI32/libjoisk32.so $BINDIR/joisk32 2>/dev/null
cp -af $CHROMEDIR/. $BINDIR/chromeos
chmod -R 755 $BINDIR

# Check if system root is installed and remove
$BOOTMODE || remove_system_su

##############
# Environment
##############

ui_print "- Constructing environment"

# Copy required files
rm -rf $JOKERBIN/* 2>/dev/null
mkdir -p $JOKERBIN 2>/dev/null
cp -af $BINDIR/. $COMMONDIR/. $BBBIN $JOKERBIN
chmod -R 755 $JOKERBIN

# addon.d
if [ -d /system/addon.d ]; then
  ui_print "- Adding addon.d survival script"
  blockdev --setrw /dev/block/mapper/system$SLOT 2>/dev/null
  mount -o rw,remount /system || mount -o rw,remount /
  ADDOND=/system/addon.d/99-magisk.sh
  cp -af $COMMONDIR/addon.d.sh $ADDOND
  chmod 755 $ADDOND
fi

##################
# Image Patching
##################

install_magisk

# Cleanups
$BOOTMODE || recovery_cleanup
rm -rf $TMPDIR

ui_print "- Done"
exit 0
