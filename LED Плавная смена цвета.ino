#include <FastLED.h>

#define NUM_LEDS 2        // Общее количество светодиодов в ленте
#define DATA_PIN 6         // Пин данных для подключения к ленте

CRGB leds[NUM_LEDS];     // Массив светодиодов

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // Инициализация ленты
  FastLED.setBrightness(255);                                 // Установка яркости (от 0 до 255)
}

void loop() {
  // Автоматическая смена цвета
  static uint8_t hue = 0;               // Переменная для хранения текущего значения цвета
  static uint8_t colorChangeInterval = 1; // Интервал смены цвета (в тиках loop())
  
  EVERY_N_MILLISECONDS(100) {
    // Увеличение значения цвета с определенным интервалом
    hue += colorChangeInterval;
    if (hue >= 255) {
      hue = 0; // Значение цвета переводим в диапазон от 0 до 255
    }
  }

  // Плавное мигание светодиодной лентой
  static uint8_t fadeInSpeed = 1;          // Скорость затухания (загорания) светода
  static uint8_t fadeOutSpeed = 2;         // Скорость резкого выключения светода

  // Загорание светодиодов с плавным затуханием
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);        // Установка текущего цвета для текущего светодиода
    leds[i].fadeToBlackBy(fadeInSpeed);   // Плавное затухание текущего светодиода
  }

  FastLED.show();                          // Отправка данных на светодиодную ленту

  // Быстрое затухание всех светодиодов
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(fadeOutSpeed);  // Быстрое затухание всех светодиодов
  }
}
