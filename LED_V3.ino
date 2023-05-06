#include <FastLED.h>

#define LED_PIN 6 // Пин подключения LED
#define LED_COUNT 2 // Количество LED

CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT); // Инициализация библиотеки
  FastLED.setBrightness(100); // Установка яркости
}

void loop() {
  // Случайный цвет для каждого нового цикла
  CRGB color = CRGB(random(255), random(255), random(255));
  
  // Цикл для постепенного увеличения яркости
  for(int i = 0; i < 254; i++) {
    leds[0] = color % (i + 1); // Установка цвета LED с увеличенной яркостью
    FastLED.show(); // Обновление состояния LED
    delay(20); // Задержка для эффекта плавности
  }

  // Цикл для постепенного уменьшения яркости
  for(int i = 254; i >= 0; i--) {
    leds[0] = color % (i + 1); // Установка цвета LED с уменьшенной яркостью
    FastLED.show(); // Обновление состояния LED
    delay(20); // Задержка для эффекта плавности
  }
}
