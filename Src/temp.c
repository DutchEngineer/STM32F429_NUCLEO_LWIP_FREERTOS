
float getMCUTemperature() {

	static float temp = 25.0;

	temp = temp + 1.2;
	if (temp > 27.8){
		temp = temp - 25.7;
	}

	return temp;
}
