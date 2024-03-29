/*
 * Solution 7
 * Copyright (c) 2024. de-Manzanares
 * Contact: git.in.touch@dmanz.org
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * https://projecteuler.net/problem=7
 */

#ifndef PROJECTEULERSOLUTIONS_SOLUTION_7_H
#define PROJECTEULERSOLUTIONS_SOLUTION_7_H

#include <cstdint>
#include <iostream>
#include <vector>

class Solution_007 {
public:
    void print_solution()
    {
        Stopwatch stopwatch;
        stopwatch.start();
        int nthPrime = 10001;
        std::vector<size_t> primeList = {2};
        size_t number;
        bool hasPrimeFactor;
        bool provenComposite;
        bool generatePrimes = true;

        for (number = 3; generatePrimes; number++) {
            provenComposite = false;
            for (int i = 0; i < primeList.size() && !provenComposite; i++) {
                hasPrimeFactor = (number % primeList[i] == 0);
                if (hasPrimeFactor) {
                    provenComposite = true;
                }
            }
            if (!provenComposite) {
                primeList.push_back(number);
            }
            generatePrimes = number < SIZE_MAX && primeList.size() < nthPrime;
        }
        std::cout << primeList[nthPrime - 1] << std::endl;
        stopwatch.stop();
    }
};

#endif //PROJECTEULERSOLUTIONS_SOLUTION_7_H
