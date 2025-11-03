OBJS += $(BUILD)/src/datapoint/datapoint_16_1_False.o

$(BUILD)/src/datapoint/datapoint_16_1_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=1  -DPARAM_DESC="\"(count = 16, datalen = 1, packed = False)\"" -DPARAM_ENTRY=datapoint_16_1_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_1_True.o

$(BUILD)/src/datapoint/datapoint_16_1_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=1 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 1, packed = True)\"" -DPARAM_ENTRY=datapoint_16_1_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_2_False.o

$(BUILD)/src/datapoint/datapoint_16_2_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=2  -DPARAM_DESC="\"(count = 16, datalen = 2, packed = False)\"" -DPARAM_ENTRY=datapoint_16_2_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_2_True.o

$(BUILD)/src/datapoint/datapoint_16_2_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=2 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 2, packed = True)\"" -DPARAM_ENTRY=datapoint_16_2_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_3_False.o

$(BUILD)/src/datapoint/datapoint_16_3_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=3  -DPARAM_DESC="\"(count = 16, datalen = 3, packed = False)\"" -DPARAM_ENTRY=datapoint_16_3_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_3_True.o

$(BUILD)/src/datapoint/datapoint_16_3_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=3 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 3, packed = True)\"" -DPARAM_ENTRY=datapoint_16_3_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_4_False.o

$(BUILD)/src/datapoint/datapoint_16_4_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=4  -DPARAM_DESC="\"(count = 16, datalen = 4, packed = False)\"" -DPARAM_ENTRY=datapoint_16_4_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_4_True.o

$(BUILD)/src/datapoint/datapoint_16_4_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=4 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 4, packed = True)\"" -DPARAM_ENTRY=datapoint_16_4_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_5_False.o

$(BUILD)/src/datapoint/datapoint_16_5_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=5  -DPARAM_DESC="\"(count = 16, datalen = 5, packed = False)\"" -DPARAM_ENTRY=datapoint_16_5_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_5_True.o

$(BUILD)/src/datapoint/datapoint_16_5_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=5 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 5, packed = True)\"" -DPARAM_ENTRY=datapoint_16_5_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_6_False.o

$(BUILD)/src/datapoint/datapoint_16_6_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=6  -DPARAM_DESC="\"(count = 16, datalen = 6, packed = False)\"" -DPARAM_ENTRY=datapoint_16_6_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_6_True.o

$(BUILD)/src/datapoint/datapoint_16_6_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=6 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 6, packed = True)\"" -DPARAM_ENTRY=datapoint_16_6_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_7_False.o

$(BUILD)/src/datapoint/datapoint_16_7_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=7  -DPARAM_DESC="\"(count = 16, datalen = 7, packed = False)\"" -DPARAM_ENTRY=datapoint_16_7_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_7_True.o

$(BUILD)/src/datapoint/datapoint_16_7_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=7 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 7, packed = True)\"" -DPARAM_ENTRY=datapoint_16_7_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_8_False.o

$(BUILD)/src/datapoint/datapoint_16_8_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=8  -DPARAM_DESC="\"(count = 16, datalen = 8, packed = False)\"" -DPARAM_ENTRY=datapoint_16_8_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_8_True.o

$(BUILD)/src/datapoint/datapoint_16_8_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=8 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 8, packed = True)\"" -DPARAM_ENTRY=datapoint_16_8_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_9_False.o

$(BUILD)/src/datapoint/datapoint_16_9_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=9  -DPARAM_DESC="\"(count = 16, datalen = 9, packed = False)\"" -DPARAM_ENTRY=datapoint_16_9_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_9_True.o

$(BUILD)/src/datapoint/datapoint_16_9_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=9 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 9, packed = True)\"" -DPARAM_ENTRY=datapoint_16_9_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_10_False.o

$(BUILD)/src/datapoint/datapoint_16_10_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=10  -DPARAM_DESC="\"(count = 16, datalen = 10, packed = False)\"" -DPARAM_ENTRY=datapoint_16_10_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_10_True.o

$(BUILD)/src/datapoint/datapoint_16_10_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=10 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 10, packed = True)\"" -DPARAM_ENTRY=datapoint_16_10_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_11_False.o

$(BUILD)/src/datapoint/datapoint_16_11_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=11  -DPARAM_DESC="\"(count = 16, datalen = 11, packed = False)\"" -DPARAM_ENTRY=datapoint_16_11_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_11_True.o

$(BUILD)/src/datapoint/datapoint_16_11_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=11 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 11, packed = True)\"" -DPARAM_ENTRY=datapoint_16_11_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_12_False.o

$(BUILD)/src/datapoint/datapoint_16_12_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=12  -DPARAM_DESC="\"(count = 16, datalen = 12, packed = False)\"" -DPARAM_ENTRY=datapoint_16_12_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_12_True.o

$(BUILD)/src/datapoint/datapoint_16_12_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=12 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 12, packed = True)\"" -DPARAM_ENTRY=datapoint_16_12_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_13_False.o

$(BUILD)/src/datapoint/datapoint_16_13_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=13  -DPARAM_DESC="\"(count = 16, datalen = 13, packed = False)\"" -DPARAM_ENTRY=datapoint_16_13_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_13_True.o

$(BUILD)/src/datapoint/datapoint_16_13_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=13 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 13, packed = True)\"" -DPARAM_ENTRY=datapoint_16_13_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_14_False.o

$(BUILD)/src/datapoint/datapoint_16_14_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=14  -DPARAM_DESC="\"(count = 16, datalen = 14, packed = False)\"" -DPARAM_ENTRY=datapoint_16_14_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_14_True.o

$(BUILD)/src/datapoint/datapoint_16_14_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=14 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 14, packed = True)\"" -DPARAM_ENTRY=datapoint_16_14_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_15_False.o

$(BUILD)/src/datapoint/datapoint_16_15_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=15  -DPARAM_DESC="\"(count = 16, datalen = 15, packed = False)\"" -DPARAM_ENTRY=datapoint_16_15_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_15_True.o

$(BUILD)/src/datapoint/datapoint_16_15_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=15 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 15, packed = True)\"" -DPARAM_ENTRY=datapoint_16_15_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_16_False.o

$(BUILD)/src/datapoint/datapoint_16_16_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=16  -DPARAM_DESC="\"(count = 16, datalen = 16, packed = False)\"" -DPARAM_ENTRY=datapoint_16_16_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_16_True.o

$(BUILD)/src/datapoint/datapoint_16_16_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=16 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 16, packed = True)\"" -DPARAM_ENTRY=datapoint_16_16_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_17_False.o

$(BUILD)/src/datapoint/datapoint_16_17_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=17  -DPARAM_DESC="\"(count = 16, datalen = 17, packed = False)\"" -DPARAM_ENTRY=datapoint_16_17_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_17_True.o

$(BUILD)/src/datapoint/datapoint_16_17_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=17 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 17, packed = True)\"" -DPARAM_ENTRY=datapoint_16_17_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_18_False.o

$(BUILD)/src/datapoint/datapoint_16_18_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=18  -DPARAM_DESC="\"(count = 16, datalen = 18, packed = False)\"" -DPARAM_ENTRY=datapoint_16_18_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_18_True.o

$(BUILD)/src/datapoint/datapoint_16_18_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=18 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 18, packed = True)\"" -DPARAM_ENTRY=datapoint_16_18_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_19_False.o

$(BUILD)/src/datapoint/datapoint_16_19_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=19  -DPARAM_DESC="\"(count = 16, datalen = 19, packed = False)\"" -DPARAM_ENTRY=datapoint_16_19_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_19_True.o

$(BUILD)/src/datapoint/datapoint_16_19_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=19 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 19, packed = True)\"" -DPARAM_ENTRY=datapoint_16_19_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_20_False.o

$(BUILD)/src/datapoint/datapoint_16_20_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=20  -DPARAM_DESC="\"(count = 16, datalen = 20, packed = False)\"" -DPARAM_ENTRY=datapoint_16_20_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_20_True.o

$(BUILD)/src/datapoint/datapoint_16_20_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=20 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 20, packed = True)\"" -DPARAM_ENTRY=datapoint_16_20_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_21_False.o

$(BUILD)/src/datapoint/datapoint_16_21_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=21  -DPARAM_DESC="\"(count = 16, datalen = 21, packed = False)\"" -DPARAM_ENTRY=datapoint_16_21_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_21_True.o

$(BUILD)/src/datapoint/datapoint_16_21_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=21 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 21, packed = True)\"" -DPARAM_ENTRY=datapoint_16_21_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_22_False.o

$(BUILD)/src/datapoint/datapoint_16_22_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=22  -DPARAM_DESC="\"(count = 16, datalen = 22, packed = False)\"" -DPARAM_ENTRY=datapoint_16_22_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_22_True.o

$(BUILD)/src/datapoint/datapoint_16_22_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=22 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 22, packed = True)\"" -DPARAM_ENTRY=datapoint_16_22_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_23_False.o

$(BUILD)/src/datapoint/datapoint_16_23_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=23  -DPARAM_DESC="\"(count = 16, datalen = 23, packed = False)\"" -DPARAM_ENTRY=datapoint_16_23_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_23_True.o

$(BUILD)/src/datapoint/datapoint_16_23_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=23 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 23, packed = True)\"" -DPARAM_ENTRY=datapoint_16_23_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_24_False.o

$(BUILD)/src/datapoint/datapoint_16_24_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=24  -DPARAM_DESC="\"(count = 16, datalen = 24, packed = False)\"" -DPARAM_ENTRY=datapoint_16_24_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_24_True.o

$(BUILD)/src/datapoint/datapoint_16_24_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=24 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 24, packed = True)\"" -DPARAM_ENTRY=datapoint_16_24_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_25_False.o

$(BUILD)/src/datapoint/datapoint_16_25_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=25  -DPARAM_DESC="\"(count = 16, datalen = 25, packed = False)\"" -DPARAM_ENTRY=datapoint_16_25_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_25_True.o

$(BUILD)/src/datapoint/datapoint_16_25_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=25 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 25, packed = True)\"" -DPARAM_ENTRY=datapoint_16_25_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_26_False.o

$(BUILD)/src/datapoint/datapoint_16_26_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=26  -DPARAM_DESC="\"(count = 16, datalen = 26, packed = False)\"" -DPARAM_ENTRY=datapoint_16_26_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_26_True.o

$(BUILD)/src/datapoint/datapoint_16_26_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=26 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 26, packed = True)\"" -DPARAM_ENTRY=datapoint_16_26_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_27_False.o

$(BUILD)/src/datapoint/datapoint_16_27_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=27  -DPARAM_DESC="\"(count = 16, datalen = 27, packed = False)\"" -DPARAM_ENTRY=datapoint_16_27_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_27_True.o

$(BUILD)/src/datapoint/datapoint_16_27_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=27 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 27, packed = True)\"" -DPARAM_ENTRY=datapoint_16_27_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_28_False.o

$(BUILD)/src/datapoint/datapoint_16_28_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=28  -DPARAM_DESC="\"(count = 16, datalen = 28, packed = False)\"" -DPARAM_ENTRY=datapoint_16_28_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_28_True.o

$(BUILD)/src/datapoint/datapoint_16_28_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=28 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 28, packed = True)\"" -DPARAM_ENTRY=datapoint_16_28_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_29_False.o

$(BUILD)/src/datapoint/datapoint_16_29_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=29  -DPARAM_DESC="\"(count = 16, datalen = 29, packed = False)\"" -DPARAM_ENTRY=datapoint_16_29_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_29_True.o

$(BUILD)/src/datapoint/datapoint_16_29_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=29 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 29, packed = True)\"" -DPARAM_ENTRY=datapoint_16_29_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_30_False.o

$(BUILD)/src/datapoint/datapoint_16_30_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=30  -DPARAM_DESC="\"(count = 16, datalen = 30, packed = False)\"" -DPARAM_ENTRY=datapoint_16_30_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_30_True.o

$(BUILD)/src/datapoint/datapoint_16_30_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=30 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 30, packed = True)\"" -DPARAM_ENTRY=datapoint_16_30_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_31_False.o

$(BUILD)/src/datapoint/datapoint_16_31_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=31  -DPARAM_DESC="\"(count = 16, datalen = 31, packed = False)\"" -DPARAM_ENTRY=datapoint_16_31_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_31_True.o

$(BUILD)/src/datapoint/datapoint_16_31_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=31 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 31, packed = True)\"" -DPARAM_ENTRY=datapoint_16_31_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_32_False.o

$(BUILD)/src/datapoint/datapoint_16_32_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=32  -DPARAM_DESC="\"(count = 16, datalen = 32, packed = False)\"" -DPARAM_ENTRY=datapoint_16_32_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_16_32_True.o

$(BUILD)/src/datapoint/datapoint_16_32_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=16 -DPARAM_DATALEN=32 -DPARAM_PACKED -DPARAM_DESC="\"(count = 16, datalen = 32, packed = True)\"" -DPARAM_ENTRY=datapoint_16_32_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_1_False.o

$(BUILD)/src/datapoint/datapoint_64_1_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=1  -DPARAM_DESC="\"(count = 64, datalen = 1, packed = False)\"" -DPARAM_ENTRY=datapoint_64_1_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_1_True.o

$(BUILD)/src/datapoint/datapoint_64_1_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=1 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 1, packed = True)\"" -DPARAM_ENTRY=datapoint_64_1_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_2_False.o

$(BUILD)/src/datapoint/datapoint_64_2_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=2  -DPARAM_DESC="\"(count = 64, datalen = 2, packed = False)\"" -DPARAM_ENTRY=datapoint_64_2_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_2_True.o

$(BUILD)/src/datapoint/datapoint_64_2_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=2 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 2, packed = True)\"" -DPARAM_ENTRY=datapoint_64_2_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_3_False.o

$(BUILD)/src/datapoint/datapoint_64_3_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=3  -DPARAM_DESC="\"(count = 64, datalen = 3, packed = False)\"" -DPARAM_ENTRY=datapoint_64_3_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_3_True.o

$(BUILD)/src/datapoint/datapoint_64_3_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=3 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 3, packed = True)\"" -DPARAM_ENTRY=datapoint_64_3_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_4_False.o

$(BUILD)/src/datapoint/datapoint_64_4_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=4  -DPARAM_DESC="\"(count = 64, datalen = 4, packed = False)\"" -DPARAM_ENTRY=datapoint_64_4_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_4_True.o

$(BUILD)/src/datapoint/datapoint_64_4_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=4 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 4, packed = True)\"" -DPARAM_ENTRY=datapoint_64_4_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_5_False.o

$(BUILD)/src/datapoint/datapoint_64_5_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=5  -DPARAM_DESC="\"(count = 64, datalen = 5, packed = False)\"" -DPARAM_ENTRY=datapoint_64_5_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_5_True.o

$(BUILD)/src/datapoint/datapoint_64_5_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=5 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 5, packed = True)\"" -DPARAM_ENTRY=datapoint_64_5_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_6_False.o

$(BUILD)/src/datapoint/datapoint_64_6_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=6  -DPARAM_DESC="\"(count = 64, datalen = 6, packed = False)\"" -DPARAM_ENTRY=datapoint_64_6_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_6_True.o

$(BUILD)/src/datapoint/datapoint_64_6_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=6 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 6, packed = True)\"" -DPARAM_ENTRY=datapoint_64_6_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_7_False.o

$(BUILD)/src/datapoint/datapoint_64_7_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=7  -DPARAM_DESC="\"(count = 64, datalen = 7, packed = False)\"" -DPARAM_ENTRY=datapoint_64_7_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_7_True.o

$(BUILD)/src/datapoint/datapoint_64_7_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=7 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 7, packed = True)\"" -DPARAM_ENTRY=datapoint_64_7_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_8_False.o

$(BUILD)/src/datapoint/datapoint_64_8_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=8  -DPARAM_DESC="\"(count = 64, datalen = 8, packed = False)\"" -DPARAM_ENTRY=datapoint_64_8_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_8_True.o

$(BUILD)/src/datapoint/datapoint_64_8_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=8 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 8, packed = True)\"" -DPARAM_ENTRY=datapoint_64_8_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_9_False.o

$(BUILD)/src/datapoint/datapoint_64_9_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=9  -DPARAM_DESC="\"(count = 64, datalen = 9, packed = False)\"" -DPARAM_ENTRY=datapoint_64_9_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_9_True.o

$(BUILD)/src/datapoint/datapoint_64_9_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=9 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 9, packed = True)\"" -DPARAM_ENTRY=datapoint_64_9_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_10_False.o

$(BUILD)/src/datapoint/datapoint_64_10_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=10  -DPARAM_DESC="\"(count = 64, datalen = 10, packed = False)\"" -DPARAM_ENTRY=datapoint_64_10_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_10_True.o

$(BUILD)/src/datapoint/datapoint_64_10_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=10 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 10, packed = True)\"" -DPARAM_ENTRY=datapoint_64_10_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_11_False.o

$(BUILD)/src/datapoint/datapoint_64_11_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=11  -DPARAM_DESC="\"(count = 64, datalen = 11, packed = False)\"" -DPARAM_ENTRY=datapoint_64_11_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_11_True.o

$(BUILD)/src/datapoint/datapoint_64_11_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=11 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 11, packed = True)\"" -DPARAM_ENTRY=datapoint_64_11_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_12_False.o

$(BUILD)/src/datapoint/datapoint_64_12_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=12  -DPARAM_DESC="\"(count = 64, datalen = 12, packed = False)\"" -DPARAM_ENTRY=datapoint_64_12_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_12_True.o

$(BUILD)/src/datapoint/datapoint_64_12_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=12 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 12, packed = True)\"" -DPARAM_ENTRY=datapoint_64_12_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_13_False.o

$(BUILD)/src/datapoint/datapoint_64_13_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=13  -DPARAM_DESC="\"(count = 64, datalen = 13, packed = False)\"" -DPARAM_ENTRY=datapoint_64_13_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_13_True.o

$(BUILD)/src/datapoint/datapoint_64_13_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=13 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 13, packed = True)\"" -DPARAM_ENTRY=datapoint_64_13_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_14_False.o

$(BUILD)/src/datapoint/datapoint_64_14_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=14  -DPARAM_DESC="\"(count = 64, datalen = 14, packed = False)\"" -DPARAM_ENTRY=datapoint_64_14_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_14_True.o

$(BUILD)/src/datapoint/datapoint_64_14_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=14 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 14, packed = True)\"" -DPARAM_ENTRY=datapoint_64_14_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_15_False.o

$(BUILD)/src/datapoint/datapoint_64_15_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=15  -DPARAM_DESC="\"(count = 64, datalen = 15, packed = False)\"" -DPARAM_ENTRY=datapoint_64_15_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_15_True.o

$(BUILD)/src/datapoint/datapoint_64_15_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=15 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 15, packed = True)\"" -DPARAM_ENTRY=datapoint_64_15_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_16_False.o

$(BUILD)/src/datapoint/datapoint_64_16_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=16  -DPARAM_DESC="\"(count = 64, datalen = 16, packed = False)\"" -DPARAM_ENTRY=datapoint_64_16_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_16_True.o

$(BUILD)/src/datapoint/datapoint_64_16_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=16 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 16, packed = True)\"" -DPARAM_ENTRY=datapoint_64_16_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_17_False.o

$(BUILD)/src/datapoint/datapoint_64_17_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=17  -DPARAM_DESC="\"(count = 64, datalen = 17, packed = False)\"" -DPARAM_ENTRY=datapoint_64_17_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_17_True.o

$(BUILD)/src/datapoint/datapoint_64_17_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=17 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 17, packed = True)\"" -DPARAM_ENTRY=datapoint_64_17_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_18_False.o

$(BUILD)/src/datapoint/datapoint_64_18_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=18  -DPARAM_DESC="\"(count = 64, datalen = 18, packed = False)\"" -DPARAM_ENTRY=datapoint_64_18_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_18_True.o

$(BUILD)/src/datapoint/datapoint_64_18_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=18 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 18, packed = True)\"" -DPARAM_ENTRY=datapoint_64_18_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_19_False.o

$(BUILD)/src/datapoint/datapoint_64_19_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=19  -DPARAM_DESC="\"(count = 64, datalen = 19, packed = False)\"" -DPARAM_ENTRY=datapoint_64_19_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_19_True.o

$(BUILD)/src/datapoint/datapoint_64_19_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=19 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 19, packed = True)\"" -DPARAM_ENTRY=datapoint_64_19_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_20_False.o

$(BUILD)/src/datapoint/datapoint_64_20_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=20  -DPARAM_DESC="\"(count = 64, datalen = 20, packed = False)\"" -DPARAM_ENTRY=datapoint_64_20_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_20_True.o

$(BUILD)/src/datapoint/datapoint_64_20_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=20 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 20, packed = True)\"" -DPARAM_ENTRY=datapoint_64_20_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_21_False.o

$(BUILD)/src/datapoint/datapoint_64_21_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=21  -DPARAM_DESC="\"(count = 64, datalen = 21, packed = False)\"" -DPARAM_ENTRY=datapoint_64_21_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_21_True.o

$(BUILD)/src/datapoint/datapoint_64_21_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=21 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 21, packed = True)\"" -DPARAM_ENTRY=datapoint_64_21_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_22_False.o

$(BUILD)/src/datapoint/datapoint_64_22_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=22  -DPARAM_DESC="\"(count = 64, datalen = 22, packed = False)\"" -DPARAM_ENTRY=datapoint_64_22_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_22_True.o

$(BUILD)/src/datapoint/datapoint_64_22_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=22 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 22, packed = True)\"" -DPARAM_ENTRY=datapoint_64_22_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_23_False.o

$(BUILD)/src/datapoint/datapoint_64_23_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=23  -DPARAM_DESC="\"(count = 64, datalen = 23, packed = False)\"" -DPARAM_ENTRY=datapoint_64_23_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_23_True.o

$(BUILD)/src/datapoint/datapoint_64_23_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=23 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 23, packed = True)\"" -DPARAM_ENTRY=datapoint_64_23_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_24_False.o

$(BUILD)/src/datapoint/datapoint_64_24_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=24  -DPARAM_DESC="\"(count = 64, datalen = 24, packed = False)\"" -DPARAM_ENTRY=datapoint_64_24_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_24_True.o

$(BUILD)/src/datapoint/datapoint_64_24_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=24 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 24, packed = True)\"" -DPARAM_ENTRY=datapoint_64_24_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_25_False.o

$(BUILD)/src/datapoint/datapoint_64_25_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=25  -DPARAM_DESC="\"(count = 64, datalen = 25, packed = False)\"" -DPARAM_ENTRY=datapoint_64_25_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_25_True.o

$(BUILD)/src/datapoint/datapoint_64_25_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=25 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 25, packed = True)\"" -DPARAM_ENTRY=datapoint_64_25_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_26_False.o

$(BUILD)/src/datapoint/datapoint_64_26_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=26  -DPARAM_DESC="\"(count = 64, datalen = 26, packed = False)\"" -DPARAM_ENTRY=datapoint_64_26_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_26_True.o

$(BUILD)/src/datapoint/datapoint_64_26_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=26 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 26, packed = True)\"" -DPARAM_ENTRY=datapoint_64_26_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_27_False.o

$(BUILD)/src/datapoint/datapoint_64_27_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=27  -DPARAM_DESC="\"(count = 64, datalen = 27, packed = False)\"" -DPARAM_ENTRY=datapoint_64_27_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_27_True.o

$(BUILD)/src/datapoint/datapoint_64_27_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=27 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 27, packed = True)\"" -DPARAM_ENTRY=datapoint_64_27_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_28_False.o

$(BUILD)/src/datapoint/datapoint_64_28_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=28  -DPARAM_DESC="\"(count = 64, datalen = 28, packed = False)\"" -DPARAM_ENTRY=datapoint_64_28_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_28_True.o

$(BUILD)/src/datapoint/datapoint_64_28_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=28 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 28, packed = True)\"" -DPARAM_ENTRY=datapoint_64_28_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_29_False.o

$(BUILD)/src/datapoint/datapoint_64_29_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=29  -DPARAM_DESC="\"(count = 64, datalen = 29, packed = False)\"" -DPARAM_ENTRY=datapoint_64_29_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_29_True.o

$(BUILD)/src/datapoint/datapoint_64_29_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=29 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 29, packed = True)\"" -DPARAM_ENTRY=datapoint_64_29_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_30_False.o

$(BUILD)/src/datapoint/datapoint_64_30_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=30  -DPARAM_DESC="\"(count = 64, datalen = 30, packed = False)\"" -DPARAM_ENTRY=datapoint_64_30_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_30_True.o

$(BUILD)/src/datapoint/datapoint_64_30_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=30 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 30, packed = True)\"" -DPARAM_ENTRY=datapoint_64_30_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_31_False.o

$(BUILD)/src/datapoint/datapoint_64_31_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=31  -DPARAM_DESC="\"(count = 64, datalen = 31, packed = False)\"" -DPARAM_ENTRY=datapoint_64_31_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_31_True.o

$(BUILD)/src/datapoint/datapoint_64_31_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=31 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 31, packed = True)\"" -DPARAM_ENTRY=datapoint_64_31_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_32_False.o

$(BUILD)/src/datapoint/datapoint_64_32_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=32  -DPARAM_DESC="\"(count = 64, datalen = 32, packed = False)\"" -DPARAM_ENTRY=datapoint_64_32_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_64_32_True.o

$(BUILD)/src/datapoint/datapoint_64_32_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=64 -DPARAM_DATALEN=32 -DPARAM_PACKED -DPARAM_DESC="\"(count = 64, datalen = 32, packed = True)\"" -DPARAM_ENTRY=datapoint_64_32_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_1_False.o

$(BUILD)/src/datapoint/datapoint_256_1_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=1  -DPARAM_DESC="\"(count = 256, datalen = 1, packed = False)\"" -DPARAM_ENTRY=datapoint_256_1_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_1_True.o

$(BUILD)/src/datapoint/datapoint_256_1_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=1 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 1, packed = True)\"" -DPARAM_ENTRY=datapoint_256_1_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_2_False.o

$(BUILD)/src/datapoint/datapoint_256_2_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=2  -DPARAM_DESC="\"(count = 256, datalen = 2, packed = False)\"" -DPARAM_ENTRY=datapoint_256_2_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_2_True.o

$(BUILD)/src/datapoint/datapoint_256_2_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=2 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 2, packed = True)\"" -DPARAM_ENTRY=datapoint_256_2_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_3_False.o

$(BUILD)/src/datapoint/datapoint_256_3_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=3  -DPARAM_DESC="\"(count = 256, datalen = 3, packed = False)\"" -DPARAM_ENTRY=datapoint_256_3_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_3_True.o

$(BUILD)/src/datapoint/datapoint_256_3_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=3 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 3, packed = True)\"" -DPARAM_ENTRY=datapoint_256_3_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_4_False.o

$(BUILD)/src/datapoint/datapoint_256_4_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=4  -DPARAM_DESC="\"(count = 256, datalen = 4, packed = False)\"" -DPARAM_ENTRY=datapoint_256_4_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_4_True.o

$(BUILD)/src/datapoint/datapoint_256_4_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=4 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 4, packed = True)\"" -DPARAM_ENTRY=datapoint_256_4_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_5_False.o

$(BUILD)/src/datapoint/datapoint_256_5_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=5  -DPARAM_DESC="\"(count = 256, datalen = 5, packed = False)\"" -DPARAM_ENTRY=datapoint_256_5_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_5_True.o

$(BUILD)/src/datapoint/datapoint_256_5_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=5 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 5, packed = True)\"" -DPARAM_ENTRY=datapoint_256_5_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_6_False.o

$(BUILD)/src/datapoint/datapoint_256_6_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=6  -DPARAM_DESC="\"(count = 256, datalen = 6, packed = False)\"" -DPARAM_ENTRY=datapoint_256_6_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_6_True.o

$(BUILD)/src/datapoint/datapoint_256_6_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=6 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 6, packed = True)\"" -DPARAM_ENTRY=datapoint_256_6_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_7_False.o

$(BUILD)/src/datapoint/datapoint_256_7_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=7  -DPARAM_DESC="\"(count = 256, datalen = 7, packed = False)\"" -DPARAM_ENTRY=datapoint_256_7_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_7_True.o

$(BUILD)/src/datapoint/datapoint_256_7_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=7 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 7, packed = True)\"" -DPARAM_ENTRY=datapoint_256_7_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_8_False.o

$(BUILD)/src/datapoint/datapoint_256_8_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=8  -DPARAM_DESC="\"(count = 256, datalen = 8, packed = False)\"" -DPARAM_ENTRY=datapoint_256_8_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_8_True.o

$(BUILD)/src/datapoint/datapoint_256_8_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=8 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 8, packed = True)\"" -DPARAM_ENTRY=datapoint_256_8_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_9_False.o

$(BUILD)/src/datapoint/datapoint_256_9_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=9  -DPARAM_DESC="\"(count = 256, datalen = 9, packed = False)\"" -DPARAM_ENTRY=datapoint_256_9_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_9_True.o

$(BUILD)/src/datapoint/datapoint_256_9_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=9 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 9, packed = True)\"" -DPARAM_ENTRY=datapoint_256_9_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_10_False.o

$(BUILD)/src/datapoint/datapoint_256_10_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=10  -DPARAM_DESC="\"(count = 256, datalen = 10, packed = False)\"" -DPARAM_ENTRY=datapoint_256_10_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_10_True.o

$(BUILD)/src/datapoint/datapoint_256_10_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=10 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 10, packed = True)\"" -DPARAM_ENTRY=datapoint_256_10_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_11_False.o

$(BUILD)/src/datapoint/datapoint_256_11_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=11  -DPARAM_DESC="\"(count = 256, datalen = 11, packed = False)\"" -DPARAM_ENTRY=datapoint_256_11_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_11_True.o

$(BUILD)/src/datapoint/datapoint_256_11_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=11 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 11, packed = True)\"" -DPARAM_ENTRY=datapoint_256_11_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_12_False.o

$(BUILD)/src/datapoint/datapoint_256_12_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=12  -DPARAM_DESC="\"(count = 256, datalen = 12, packed = False)\"" -DPARAM_ENTRY=datapoint_256_12_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_12_True.o

$(BUILD)/src/datapoint/datapoint_256_12_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=12 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 12, packed = True)\"" -DPARAM_ENTRY=datapoint_256_12_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_13_False.o

$(BUILD)/src/datapoint/datapoint_256_13_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=13  -DPARAM_DESC="\"(count = 256, datalen = 13, packed = False)\"" -DPARAM_ENTRY=datapoint_256_13_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_13_True.o

$(BUILD)/src/datapoint/datapoint_256_13_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=13 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 13, packed = True)\"" -DPARAM_ENTRY=datapoint_256_13_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_14_False.o

$(BUILD)/src/datapoint/datapoint_256_14_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=14  -DPARAM_DESC="\"(count = 256, datalen = 14, packed = False)\"" -DPARAM_ENTRY=datapoint_256_14_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_14_True.o

$(BUILD)/src/datapoint/datapoint_256_14_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=14 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 14, packed = True)\"" -DPARAM_ENTRY=datapoint_256_14_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_15_False.o

$(BUILD)/src/datapoint/datapoint_256_15_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=15  -DPARAM_DESC="\"(count = 256, datalen = 15, packed = False)\"" -DPARAM_ENTRY=datapoint_256_15_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_15_True.o

$(BUILD)/src/datapoint/datapoint_256_15_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=15 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 15, packed = True)\"" -DPARAM_ENTRY=datapoint_256_15_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_16_False.o

$(BUILD)/src/datapoint/datapoint_256_16_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=16  -DPARAM_DESC="\"(count = 256, datalen = 16, packed = False)\"" -DPARAM_ENTRY=datapoint_256_16_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_16_True.o

$(BUILD)/src/datapoint/datapoint_256_16_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=16 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 16, packed = True)\"" -DPARAM_ENTRY=datapoint_256_16_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_17_False.o

$(BUILD)/src/datapoint/datapoint_256_17_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=17  -DPARAM_DESC="\"(count = 256, datalen = 17, packed = False)\"" -DPARAM_ENTRY=datapoint_256_17_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_17_True.o

$(BUILD)/src/datapoint/datapoint_256_17_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=17 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 17, packed = True)\"" -DPARAM_ENTRY=datapoint_256_17_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_18_False.o

$(BUILD)/src/datapoint/datapoint_256_18_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=18  -DPARAM_DESC="\"(count = 256, datalen = 18, packed = False)\"" -DPARAM_ENTRY=datapoint_256_18_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_18_True.o

$(BUILD)/src/datapoint/datapoint_256_18_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=18 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 18, packed = True)\"" -DPARAM_ENTRY=datapoint_256_18_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_19_False.o

$(BUILD)/src/datapoint/datapoint_256_19_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=19  -DPARAM_DESC="\"(count = 256, datalen = 19, packed = False)\"" -DPARAM_ENTRY=datapoint_256_19_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_19_True.o

$(BUILD)/src/datapoint/datapoint_256_19_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=19 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 19, packed = True)\"" -DPARAM_ENTRY=datapoint_256_19_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_20_False.o

$(BUILD)/src/datapoint/datapoint_256_20_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=20  -DPARAM_DESC="\"(count = 256, datalen = 20, packed = False)\"" -DPARAM_ENTRY=datapoint_256_20_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_20_True.o

$(BUILD)/src/datapoint/datapoint_256_20_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=20 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 20, packed = True)\"" -DPARAM_ENTRY=datapoint_256_20_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_21_False.o

$(BUILD)/src/datapoint/datapoint_256_21_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=21  -DPARAM_DESC="\"(count = 256, datalen = 21, packed = False)\"" -DPARAM_ENTRY=datapoint_256_21_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_21_True.o

$(BUILD)/src/datapoint/datapoint_256_21_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=21 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 21, packed = True)\"" -DPARAM_ENTRY=datapoint_256_21_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_22_False.o

$(BUILD)/src/datapoint/datapoint_256_22_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=22  -DPARAM_DESC="\"(count = 256, datalen = 22, packed = False)\"" -DPARAM_ENTRY=datapoint_256_22_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_22_True.o

$(BUILD)/src/datapoint/datapoint_256_22_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=22 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 22, packed = True)\"" -DPARAM_ENTRY=datapoint_256_22_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_23_False.o

$(BUILD)/src/datapoint/datapoint_256_23_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=23  -DPARAM_DESC="\"(count = 256, datalen = 23, packed = False)\"" -DPARAM_ENTRY=datapoint_256_23_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_23_True.o

$(BUILD)/src/datapoint/datapoint_256_23_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=23 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 23, packed = True)\"" -DPARAM_ENTRY=datapoint_256_23_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_24_False.o

$(BUILD)/src/datapoint/datapoint_256_24_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=24  -DPARAM_DESC="\"(count = 256, datalen = 24, packed = False)\"" -DPARAM_ENTRY=datapoint_256_24_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_24_True.o

$(BUILD)/src/datapoint/datapoint_256_24_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=24 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 24, packed = True)\"" -DPARAM_ENTRY=datapoint_256_24_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_25_False.o

$(BUILD)/src/datapoint/datapoint_256_25_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=25  -DPARAM_DESC="\"(count = 256, datalen = 25, packed = False)\"" -DPARAM_ENTRY=datapoint_256_25_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_25_True.o

$(BUILD)/src/datapoint/datapoint_256_25_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=25 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 25, packed = True)\"" -DPARAM_ENTRY=datapoint_256_25_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_26_False.o

$(BUILD)/src/datapoint/datapoint_256_26_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=26  -DPARAM_DESC="\"(count = 256, datalen = 26, packed = False)\"" -DPARAM_ENTRY=datapoint_256_26_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_26_True.o

$(BUILD)/src/datapoint/datapoint_256_26_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=26 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 26, packed = True)\"" -DPARAM_ENTRY=datapoint_256_26_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_27_False.o

$(BUILD)/src/datapoint/datapoint_256_27_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=27  -DPARAM_DESC="\"(count = 256, datalen = 27, packed = False)\"" -DPARAM_ENTRY=datapoint_256_27_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_27_True.o

$(BUILD)/src/datapoint/datapoint_256_27_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=27 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 27, packed = True)\"" -DPARAM_ENTRY=datapoint_256_27_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_28_False.o

$(BUILD)/src/datapoint/datapoint_256_28_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=28  -DPARAM_DESC="\"(count = 256, datalen = 28, packed = False)\"" -DPARAM_ENTRY=datapoint_256_28_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_28_True.o

$(BUILD)/src/datapoint/datapoint_256_28_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=28 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 28, packed = True)\"" -DPARAM_ENTRY=datapoint_256_28_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_29_False.o

$(BUILD)/src/datapoint/datapoint_256_29_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=29  -DPARAM_DESC="\"(count = 256, datalen = 29, packed = False)\"" -DPARAM_ENTRY=datapoint_256_29_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_29_True.o

$(BUILD)/src/datapoint/datapoint_256_29_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=29 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 29, packed = True)\"" -DPARAM_ENTRY=datapoint_256_29_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_30_False.o

$(BUILD)/src/datapoint/datapoint_256_30_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=30  -DPARAM_DESC="\"(count = 256, datalen = 30, packed = False)\"" -DPARAM_ENTRY=datapoint_256_30_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_30_True.o

$(BUILD)/src/datapoint/datapoint_256_30_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=30 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 30, packed = True)\"" -DPARAM_ENTRY=datapoint_256_30_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_31_False.o

$(BUILD)/src/datapoint/datapoint_256_31_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=31  -DPARAM_DESC="\"(count = 256, datalen = 31, packed = False)\"" -DPARAM_ENTRY=datapoint_256_31_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_31_True.o

$(BUILD)/src/datapoint/datapoint_256_31_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=31 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 31, packed = True)\"" -DPARAM_ENTRY=datapoint_256_31_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_32_False.o

$(BUILD)/src/datapoint/datapoint_256_32_False.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=32  -DPARAM_DESC="\"(count = 256, datalen = 32, packed = False)\"" -DPARAM_ENTRY=datapoint_256_32_False_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/datapoint_256_32_True.o

$(BUILD)/src/datapoint/datapoint_256_32_True.o : src/datapoint/datapoint.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -DPARAM_COUNT=256 -DPARAM_DATALEN=32 -DPARAM_PACKED -DPARAM_DESC="\"(count = 256, datalen = 32, packed = True)\"" -DPARAM_ENTRY=datapoint_256_32_True_main -save-temps -c $< -o $@

OBJS += $(BUILD)/src/datapoint/entry.o

$(BUILD)/src/datapoint/entry.o : src/datapoint/entry.c
	mkdir -p $(@D)
	$(CC) $(_CFLAGS) $(CFLAGS) -Wno-implicit-function-declaration -DALL_ENTRIES="datapoint_16_1_False_main(); datapoint_16_1_True_main(); datapoint_16_2_False_main(); datapoint_16_2_True_main(); datapoint_16_3_False_main(); datapoint_16_3_True_main(); datapoint_16_4_False_main(); datapoint_16_4_True_main(); datapoint_16_5_False_main(); datapoint_16_5_True_main(); datapoint_16_6_False_main(); datapoint_16_6_True_main(); datapoint_16_7_False_main(); datapoint_16_7_True_main(); datapoint_16_8_False_main(); datapoint_16_8_True_main(); datapoint_16_9_False_main(); datapoint_16_9_True_main(); datapoint_16_10_False_main(); datapoint_16_10_True_main(); datapoint_16_11_False_main(); datapoint_16_11_True_main(); datapoint_16_12_False_main(); datapoint_16_12_True_main(); datapoint_16_13_False_main(); datapoint_16_13_True_main(); datapoint_16_14_False_main(); datapoint_16_14_True_main(); datapoint_16_15_False_main(); datapoint_16_15_True_main(); datapoint_16_16_False_main(); datapoint_16_16_True_main(); datapoint_16_17_False_main(); datapoint_16_17_True_main(); datapoint_16_18_False_main(); datapoint_16_18_True_main(); datapoint_16_19_False_main(); datapoint_16_19_True_main(); datapoint_16_20_False_main(); datapoint_16_20_True_main(); datapoint_16_21_False_main(); datapoint_16_21_True_main(); datapoint_16_22_False_main(); datapoint_16_22_True_main(); datapoint_16_23_False_main(); datapoint_16_23_True_main(); datapoint_16_24_False_main(); datapoint_16_24_True_main(); datapoint_16_25_False_main(); datapoint_16_25_True_main(); datapoint_16_26_False_main(); datapoint_16_26_True_main(); datapoint_16_27_False_main(); datapoint_16_27_True_main(); datapoint_16_28_False_main(); datapoint_16_28_True_main(); datapoint_16_29_False_main(); datapoint_16_29_True_main(); datapoint_16_30_False_main(); datapoint_16_30_True_main(); datapoint_16_31_False_main(); datapoint_16_31_True_main(); datapoint_16_32_False_main(); datapoint_16_32_True_main(); datapoint_64_1_False_main(); datapoint_64_1_True_main(); datapoint_64_2_False_main(); datapoint_64_2_True_main(); datapoint_64_3_False_main(); datapoint_64_3_True_main(); datapoint_64_4_False_main(); datapoint_64_4_True_main(); datapoint_64_5_False_main(); datapoint_64_5_True_main(); datapoint_64_6_False_main(); datapoint_64_6_True_main(); datapoint_64_7_False_main(); datapoint_64_7_True_main(); datapoint_64_8_False_main(); datapoint_64_8_True_main(); datapoint_64_9_False_main(); datapoint_64_9_True_main(); datapoint_64_10_False_main(); datapoint_64_10_True_main(); datapoint_64_11_False_main(); datapoint_64_11_True_main(); datapoint_64_12_False_main(); datapoint_64_12_True_main(); datapoint_64_13_False_main(); datapoint_64_13_True_main(); datapoint_64_14_False_main(); datapoint_64_14_True_main(); datapoint_64_15_False_main(); datapoint_64_15_True_main(); datapoint_64_16_False_main(); datapoint_64_16_True_main(); datapoint_64_17_False_main(); datapoint_64_17_True_main(); datapoint_64_18_False_main(); datapoint_64_18_True_main(); datapoint_64_19_False_main(); datapoint_64_19_True_main(); datapoint_64_20_False_main(); datapoint_64_20_True_main(); datapoint_64_21_False_main(); datapoint_64_21_True_main(); datapoint_64_22_False_main(); datapoint_64_22_True_main(); datapoint_64_23_False_main(); datapoint_64_23_True_main(); datapoint_64_24_False_main(); datapoint_64_24_True_main(); datapoint_64_25_False_main(); datapoint_64_25_True_main(); datapoint_64_26_False_main(); datapoint_64_26_True_main(); datapoint_64_27_False_main(); datapoint_64_27_True_main(); datapoint_64_28_False_main(); datapoint_64_28_True_main(); datapoint_64_29_False_main(); datapoint_64_29_True_main(); datapoint_64_30_False_main(); datapoint_64_30_True_main(); datapoint_64_31_False_main(); datapoint_64_31_True_main(); datapoint_64_32_False_main(); datapoint_64_32_True_main(); datapoint_256_1_False_main(); datapoint_256_1_True_main(); datapoint_256_2_False_main(); datapoint_256_2_True_main(); datapoint_256_3_False_main(); datapoint_256_3_True_main(); datapoint_256_4_False_main(); datapoint_256_4_True_main(); datapoint_256_5_False_main(); datapoint_256_5_True_main(); datapoint_256_6_False_main(); datapoint_256_6_True_main(); datapoint_256_7_False_main(); datapoint_256_7_True_main(); datapoint_256_8_False_main(); datapoint_256_8_True_main(); datapoint_256_9_False_main(); datapoint_256_9_True_main(); datapoint_256_10_False_main(); datapoint_256_10_True_main(); datapoint_256_11_False_main(); datapoint_256_11_True_main(); datapoint_256_12_False_main(); datapoint_256_12_True_main(); datapoint_256_13_False_main(); datapoint_256_13_True_main(); datapoint_256_14_False_main(); datapoint_256_14_True_main(); datapoint_256_15_False_main(); datapoint_256_15_True_main(); datapoint_256_16_False_main(); datapoint_256_16_True_main(); datapoint_256_17_False_main(); datapoint_256_17_True_main(); datapoint_256_18_False_main(); datapoint_256_18_True_main(); datapoint_256_19_False_main(); datapoint_256_19_True_main(); datapoint_256_20_False_main(); datapoint_256_20_True_main(); datapoint_256_21_False_main(); datapoint_256_21_True_main(); datapoint_256_22_False_main(); datapoint_256_22_True_main(); datapoint_256_23_False_main(); datapoint_256_23_True_main(); datapoint_256_24_False_main(); datapoint_256_24_True_main(); datapoint_256_25_False_main(); datapoint_256_25_True_main(); datapoint_256_26_False_main(); datapoint_256_26_True_main(); datapoint_256_27_False_main(); datapoint_256_27_True_main(); datapoint_256_28_False_main(); datapoint_256_28_True_main(); datapoint_256_29_False_main(); datapoint_256_29_True_main(); datapoint_256_30_False_main(); datapoint_256_30_True_main(); datapoint_256_31_False_main(); datapoint_256_31_True_main(); datapoint_256_32_False_main(); datapoint_256_32_True_main(); " -c $< -o $@

