class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        const double KELVIN_CONVERTER = 273.15, MULTIPLIER = 1.80, FARENHEIT_CONVERTER = 32.00;
        vector <double> answer(2);
        answer[0] = celsius + KELVIN_CONVERTER;
        answer[1] = celsius*MULTIPLIER + FARENHEIT_CONVERTER;
        return answer;
    }
};
