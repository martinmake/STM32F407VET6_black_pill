#include "driver/status_leds.h"

namespace Driver
{
	using namespace STATUS_LEDS;

	StatusLeds status_leds;

	// METHODS
	bool StatusLeds::initialize(void)
	{
		signal(SIGNAL::OK);
		INITIALIZATION_OK("STATUS LEDS");
	}
	//
	void StatusLeds::signal(SIGNAL signal)
	{
		switch (signal)
		{
			case SIGNAL::OK:
				HAL_GPIO_WritePin(STATUS_LED_ERROR_GPIO,   STATUS_LED_ERROR_GPIO_PIN,   GPIO_PIN_SET);
				HAL_GPIO_WritePin(STATUS_LED_WARNING_GPIO, STATUS_LED_WARNING_GPIO_PIN, GPIO_PIN_SET);
				break;
			case SIGNAL::SUCCESS:
				HAL_GPIO_WritePin(STATUS_LED_ERROR_GPIO,   STATUS_LED_ERROR_GPIO_PIN,   GPIO_PIN_RESET);
				HAL_GPIO_WritePin(STATUS_LED_WARNING_GPIO, STATUS_LED_WARNING_GPIO_PIN, GPIO_PIN_RESET);
				break;
			case SIGNAL::WARNING:
				HAL_GPIO_WritePin(STATUS_LED_ERROR_GPIO,   STATUS_LED_ERROR_GPIO_PIN,   GPIO_PIN_SET);
				HAL_GPIO_WritePin(STATUS_LED_WARNING_GPIO, STATUS_LED_WARNING_GPIO_PIN, GPIO_PIN_RESET);
				break;
			case SIGNAL::ERROR:
				HAL_GPIO_WritePin(STATUS_LED_ERROR_GPIO,   STATUS_LED_ERROR_GPIO_PIN,   GPIO_PIN_RESET);
				HAL_GPIO_WritePin(STATUS_LED_WARNING_GPIO, STATUS_LED_WARNING_GPIO_PIN, GPIO_PIN_SET);
				break;
		}
	}
}
