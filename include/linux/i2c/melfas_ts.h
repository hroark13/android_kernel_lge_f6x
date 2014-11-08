/*
 * include/linux/melfas_ts.h - platform data structure for MCS Series sensor
 *
 * Copyright (C) 2010 Melfas, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _LINUX_MELFAS_TS_H
#define _LINUX_MELFAS_TS_H

#define MELFAS_TS_NAME "melfas-ts"

#define MAX_NUM_OF_BUTTON			4

struct melfas_tsi_platform_data {
	uint32_t version;
	int max_x;
	int max_y;
	int max_pressure;
	int max_width;
	int gpio_scl;
	int gpio_sda;
	int i2c_int_gpio;
	int (*power_enable)(int en, bool log_en);
	int gpio_ldo;
	unsigned short ic_booting_delay;		/* ms */
	unsigned long report_period;			/* ns */
	unsigned char num_of_finger;
	unsigned char num_of_button;
	unsigned short button[MAX_NUM_OF_BUTTON];
	int x_max;
	int y_max;
	unsigned char fw_ver;
	unsigned int palm_threshold;
	unsigned int delta_pos_threshold;
};

/* [LGE_CHANGE_S] 20130205 mystery184.kim@lge.com 
  * mms134s f/w upgrade initialize porting 
  */
#if defined(CONFIG_TOUCHSCREEN_MELFAS_MMS134)
int melfas_touch_i2c_read(unsigned char* buf, unsigned char reg, int len);
int melfas_touch_i2c_write(unsigned char* buf, unsigned char reg, int len);
int melfas_touch_i2c_read_len(unsigned char* buf, int len);
#endif
/* [LGE_CHANGE_E] mms134s f/w upgrade initialize porting  */

#endif /* _LINUX_MELFAS_TS_H */
