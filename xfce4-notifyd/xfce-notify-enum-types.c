


#include "xfce-notify-enum-types.h"
#include "xfce4-notifyd/xfce-notify-window.h"

/* enumerations from "./xfce4-notifyd/xfce-notify-window.h" */
GType
xfce_notify_close_reason_get_type(void)
{
	static GType type = 0;
	if(type == 0) {
	static const GEnumValue values[] = {
	{ XFCE_NOTIFY_CLOSE_REASON_EXPIRED, "XFCE_NOTIFY_CLOSE_REASON_EXPIRED", "expired" },
	{ XFCE_NOTIFY_CLOSE_REASON_DISMISSED, "XFCE_NOTIFY_CLOSE_REASON_DISMISSED", "dismissed" },
	{ XFCE_NOTIFY_CLOSE_REASON_CLIENT, "XFCE_NOTIFY_CLOSE_REASON_CLIENT", "client" },
	{ XFCE_NOTIFY_CLOSE_REASON_UNKNOWN, "XFCE_NOTIFY_CLOSE_REASON_UNKNOWN", "unknown" },
	{ 0, NULL, NULL }
	};
	type = g_enum_register_static("XfceNotifyCloseReason", values);
  }
	return type;
}



