//
// Created by alculquicondor on 9/6/16.
//

#ifndef GENETIC_ALGORITHM_VARIABLEDESCRIPTION_H
#define GENETIC_ALGORITHM_VARIABLEDESCRIPTION_H


class VariableDescription {
private:
    double minValue, maxValue, precision;

public:
    VariableDescription(double minValue, double maxValue, double precision) :
            minValue(minValue), maxValue(maxValue), precision(precision) {}

    double getMinValue() const {
        return minValue;
    }

    void setMinValue(double minValue) {
        VariableDescription::minValue = minValue;
    }

    double getMaxValue() const {
        return maxValue;
    }

    void setMaxValue(double maxValue) {
        VariableDescription::maxValue = maxValue;
    }

    double getPrecision() const {
        return precision;
    }

    void setPrecision(double precision) {
        VariableDescription::precision = precision;
    }
};


#endif //GENETIC_ALGORITHM_VARIABLEDESCRIPTION_H
