dnl
dnl This file was autogenerated from "configure.ac.in".
dnl Edit that file instead!
dnl

dnl configure.ac
dnl
dnl xfce4-notifyd - server-side implementation of the fd.o notifications spec
dnl
dnl Copyright (c) 2008 Brian Tarricone <brian@tarricone.org>
dnl

dnl version info
m4_define([xfce4_notifyd_version_major], [0])
m4_define([xfce4_notifyd_version_minor], [3])
m4_define([xfce4_notifyd_version_micro], [4])
m4_define([xfce4_notifyd_version_build], [e725359])
m4_define([xfce4_notifyd_version_tag], [])
m4_define([xfce4_notifyd_version], [xfce4_notifyd_version_major().xfce4_notifyd_version_minor().xfce4_notifyd_version_micro()ifelse(xfce4_notifyd_version_tag(), [git], [xfce4_notifyd_version_tag()-xfce4_notifyd_version_build()], [xfce4_notifyd_version_tag()])])

m4_define([notifications_spec_version], [0.9])

dnl init autoconf
AC_INIT([xfce4-notifyd], [xfce4_notifyd_version],
        [http://bugzilla.xfce.org/enter_bug.cgi?product=Xfce4-notifyd],
        [xfce4-notifyd])
AC_PREREQ([2.59c])
AC_CONFIG_SRCDIR([xfce4-notifyd/main.c])
AC_CONFIG_HEADERS([config.h])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

dnl init automake
AM_INIT_AUTOMAKE([1.8 dist-bzip2 tar-ustar no-dist-gzip subdir-objects])
AM_MAINTAINER_MODE()

dnl set helper path prefix
AC_ARG_WITH([helper-path-prefix],
            [AC_HELP_STRING([--with-helper-path-prefix=PATH],
                            [Path prefix under which helper executables will be installed (default: $libdir)])],
            [HELPER_PATH_PREFIX="$withval"],
            [HELPER_PATH_PREFIX="$libdir"])
AC_SUBST([HELPER_PATH_PREFIX])

dnl check for UNIX variants
AC_USE_SYSTEM_EXTENSIONS()

dnl check for basic programs
AC_PROG_CC()
AM_PROG_CC_C_O()
AC_PROG_LD()
AC_PROG_INSTALL()
AC_PROG_INTLTOOL()
LT_PREREQ([2.2.6])
LT_INIT([disable-static])

dnl check for standard header files
AC_HEADER_STDC()
AC_CHECK_HEADERS([errno.h fcntl.h  grp.h signal.h stdlib.h string.h \
                  sys/stat.h sys/time.h sys/types.h sys/wait.h \
                  unistd.h])

dnl Check for i18n support
XDT_I18N([ar ast bg ca cs da de el en_AU en_GB es eu fi fr gl he hr hu id is it ja kk ko lt lv ms nb nl oc pa pl pt_BR pt ro ru si sk sl sq sr sv th tr ug uk vi zh_CN zh_TW ])

dnl check for x11
XDT_CHECK_LIBX11_REQUIRE()

dnl required
XDT_CHECK_PACKAGE([LIBXFCE4UTIL], [libxfce4util-1.0], [4.12.0])
XDT_CHECK_PACKAGE([LIBXFCE4UI], [libxfce4ui-2], [4.12.0])
XDT_CHECK_PACKAGE([XFCONF], [libxfconf-0], [4.10.0])
XDT_CHECK_PACKAGE([GIO], [gio-2.0], [2.42.0])
XDT_CHECK_PACKAGE([GIO_UNIX], [gio-unix-2.0], [2.42.0])
XDT_CHECK_PACKAGE([LIBNOTIFY], [libnotify], [0.7.0])

PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3.20], [HAVE_GTK_320=true], [
  PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3.14], [HAVE_GTK_320=false], [])
])
AM_CONDITIONAL([HAVE_GTK_320], [test "x$HAVE_GTK_320" = "xtrue"])

dnl ***********************************
dnl *** Check for gdbus-codegen ***
dnl ***********************************
AC_ARG_VAR([GDBUS_CODEGEN], [D-Bus code and documentation generator from XML D-Bus interface definitions])
AC_PATH_PROG([GDBUS_CODEGEN], [gdbus-codegen], [no])
if test x"$GDBUS_CODEGEN" = x"no"; then
  AC_MSG_ERROR([could not find gdbus-codegen in \$PATH. You can run
  ./configure GDBUS_CODEGEN=/path/to/gdbus-codegen to define
  a custom location for it.])
fi

AC_PATH_PROG([DBUS_BINDING_TOOL], [dbus-binding-tool])
AS_IF([test -z "$DBUS_BINDING_TOOL"],
[
  echo '*** The program "dbus-binding-tool" is required to build.'
  exit 1
])

AS_IF([test "x$USE_MAINTAINER_MODE" = "xyes"],
[
  AC_PATH_PROG([EXO_CSOURCE], [exo-csource])
  AS_IF([test -z "$EXO_CSOURCE"],
  [
    echo '*** The program "exo-csource" is required to build when --enable-maintainer-mode'
    echo '*** is specified.'
    exit 1
  ])
])

dnl legacy support
AC_ARG_ENABLE([old-notification-closed-signature],
              [AS_HELP_STRING([--enable-old-notification-closed-signature],
                              [Use the old NotificationClosed signal signature that leaves out the 'reason' parameter.  You want to enable this if your system has libnotify 0.4.4 or earlier.])],
              [use_old_nc_sig=$enableval], [use_old_nc_sig=no])
AS_IF([test "x$use_old_nc_sig" = "xyes"],
      [AC_DEFINE([USE_OLD_NOTIFICATION_CHANGED_SIGNATURE], [1],
                 [Set if we should use the old NotificationClosed signal signature])])

dnl legacy support
AC_ARG_ENABLE([old-get-server-information-signature],
              [AS_HELP_STRING([--enable-old-get-server-information-signature],
                              [Use the old GetServerInformation method signature that leaves out the 'spec_version' parameter. (default=no)])],
              [use_old_gsi_sig=$enableval], [use_old_gsi_sig=no])
AS_IF([test "x$use_old_gsi_sig" = "xyes"],
      [AC_DEFINE([USE_OLD_GET_SERVER_INFORMATION_SIGNATURE], [1],
                 [Set if we should use the old GetServerInformation method signature])])
AM_CONDITIONAL([USE_OLD_GET_SERVER_INFORMATION_SIGNATURE],
               [test "x$use_old_gsi_sig" = "xyes"])

dnl create #define for spec version
AC_DEFINE_UNQUOTED([NOTIFICATIONS_SPEC_VERSION], ["notifications_spec_version"],
                   [Set to the version of the freedesktop.org notifications spec we support])

dnl check for debugging support
XDT_FEATURE_DEBUG()

AC_OUTPUT(
[
    Makefile
    po/Makefile.in
])
