#include "termoresistor.h"
#include "adcTermo.h"

uint32_t adc_value = 0;
uint32_t table_value = 0;

int i = 0;
int flag = 0;

double result = 0;
double k = 0;

const int temp_table0_55_05[] = 
{ 
    3197, 3178, 3158, 3138, 3118, 3097, 3077, 3056,
    3035, 3014, 2993, 2971, 2949, 2927, 2905, 2883,
    2860, 2837, 2815, 2792, 2769, 2746, 2722, 2699,
    2676, 2652, 2628, 2605, 2581, 2557, 2533, 2509,
    2485, 2460, 2436, 2412, 2388, 2363, 2339, 2315,
    2290, 2266, 2241, 2217, 2193, 2169, 2144, 2120,
    2096, 2072, 2048, 2024, 2000, 1976, 1953, 1929,
    1906, 1882, 1859, 1836, 1813, 1790, 1767, 1744,
    1721, 1698, 1676, 1653, 1631, 1609, 1587, 1566,
    1544, 1523, 1502, 1481, 1460, 1439, 1419, 1399,
    1379, 1359, 1340, 1320, 1301, 1283, 1264, 1246,
    1227, 1209, 1192, 1174, 1157, 1139, 1122, 1105,
    1089, 1073, 1056, 1040, 1025, 1009, 993, 978,
    963, 948, 934, 919, 905, 891, 877
};

void LinearSearch()
{
	HAL_ADC_Start(&adcStruct);
 	adc_value = HAL_ADC_GetValue(&adcStruct);
	flag = 0; i = 0;
	
	while(flag != 1)
	{
		table_value = temp_table0_55_05[i];
		if(adc_value >= table_value)
		{
			flag = 1;
		}
		else
		{
			i++;
		}
	}
	k = i;
	result = k * TEMPERATURE_STEP_TABLE + TEMPERATURE_UNDER;
}







