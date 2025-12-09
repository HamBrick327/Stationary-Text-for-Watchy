#ifndef SETTINGS_H
#define SETTINGS_H
#include <stdint.h>
#include <Watchy.h>
#include "secrets.h"

// --- Define the settings struct if the library does not provide it ---
/*
typedef struct watchySettings {
    const char *cityID;
    const char *lat;
    const char *lon;
    const char *weatherAPIKey;
    const char *weatherURL;
    const char *weatherUnit;
    const char *weatherLang;
    int weatherUpdateInterval;
    bool defaultNTPServer;
    const char *ntpServer;
    int gmtOffset;
    int dstOffset;
    bool vibrateOClock;
} watchySettings;*/

//Weather Settings
// CITY_ID defined in secrets.h
//#define CITY_ID "5128581" //New York City https://openweathermap.org/current#cityid

//You can also use LAT,LON for your location instead of CITY_ID, but not both
//#define LAT "40.7127" //New York City, Looked up on https://www.latlong.net/
//#define LON "-74.0059"

#ifdef CITY_ID
    #define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id={cityID}&lang={lang}&units={units}&appid={apiKey}" //open weather api using city ID
#else
    #define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&lang={lang}&units={units}&appid={apiKey}" //open weather api using lat lon
#endif

#define TEMP_UNIT "imperial" //metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 //must be greater than 5, measured in minutes
//NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * -7 //New York is UTC -5 EST, -4 EDT, will be overwritten by weather data

watchySettings settings{
    #ifdef CITY_ID
        .cityID = CITY_ID,
    #else
        .cityID = "",
        .lat = LAT,
        .lon = LON,
    #endif
    .weatherAPIKey = OPENWEATHERMAP_APIKEY,
    .weatherURL = OPENWEATHERMAP_URL,
    .weatherUnit = TEMP_UNIT,
    .weatherLang = TEMP_LANG,
    .weatherUpdateInterval = WEATHER_UPDATE_INTERVAL,
    .ntpServer = NTP_SERVER,
    .gmtOffset = GMT_OFFSET_SEC,
    .vibrateOClock = true,
};

#endif
