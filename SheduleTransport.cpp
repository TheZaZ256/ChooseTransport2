#include "SheduleTransport.h"

list<Way> SheduleTransport::listOfWays()
{
    list<Way> list{

        // Прямые пути без пересадок
        {"Moscow", "Rovno", TransportType::AIRPLANE, "2023-10-15", "10:00", "2023-10-15", "12:00", 150.0, 1},
        {"Moscow", "Rovno", TransportType::TRAIN, "2023-10-15", "08:00", "2023-10-15", "20:00", 80.0, 2},
        {"Moscow", "Rovno", TransportType::CAR, "2023-10-15", "07:00", "2023-10-17", "22:00", 50.0, 1},

        //Пути с одной пересадкой
        {"Moscow", "Kyiv", TransportType::TRAIN, "2023-10-15", "08:00", "2023-10-15", "23:50", 50.0, 2},
        {"Kyiv", "Rovno", TransportType::CAR, "2023-10-16", "01:55", "2023-10-16", "18:00", 20.0, 1},

        {"Moscow", "Minsk", TransportType::CAR, "2023-10-15", "09:00", "2023-10-15", "15:00", 40.0, 2},
        {"Minsk", "Rovno", TransportType::TRAIN, "2023-10-15", "18:00", "2023-10-15", "22:00", 60.0, 1},

        // Пути с двумя пересадками
        {"Moscow", "Warsaw", TransportType::AIRPLANE, "2023-10-15", "06:00", "2023-10-15", "08:00", 120.0, 1},
        {"Warsaw", "Lviv", TransportType::CAR, "2023-10-15", "10:00", "2023-10-15", "14:00", 30.0, 1},
        {"Lviv", "Rovno", TransportType::CAR, "2023-10-15", "16:00", "2023-10-15", "17:00", 15.0, 1},

        {"Moscow", "St. Petersburg", TransportType::TRAIN, "2023-10-15", "07:00", "2023-10-15", "12:00", 70.0, 2},
        {"St. Petersburg", "Kyiv", TransportType::AIRPLANE, "2023-10-15", "13:00", "2023-10-15", "15:00", 100.0, 1},
        {"Kyiv", "Rovno", TransportType::CAR, "2023-10-15", "16:00", "2023-10-15", "18:00", 20.0, 1},


        // Пути с тремя пересадками
        {"Moscow", "Berlin", TransportType::AIRPLANE, "2023-10-15", "05:00", "2023-10-15", "07:00", 200.0, 1},
        {"Berlin", "Warsaw", TransportType::TRAIN, "2023-10-15", "09:00", "2023-10-15", "12:00", 50.0, 2},
        {"Warsaw", "Lviv", TransportType::CAR, "2023-10-15", "15:00", "2023-10-15", "18:00", 30.0, 1},
        {"Lviv", "Rovno", TransportType::CAR, "2023-10-15", "20:00", "2023-10-15", "21:00", 15.0, 1},

        // Пути с четырьмя пересадками
        {"Moscow", "Paris", TransportType::AIRPLANE, "2023-10-15", "04:00", "2023-10-15", "07:00", 300.0, 1},
        {"Paris", "Berlin", TransportType::TRAIN, "2023-10-15", "08:00", "2023-10-15", "12:00", 80.0, 2},
        {"Berlin", "Warsaw", TransportType::TRAIN, "2023-10-15", "13:00", "2023-10-15", "17:00", 50.0, 1},
        {"Warsaw", "Lviv", TransportType::CAR, "2023-10-15", "18:00", "2023-10-15", "22:00", 30.0, 1},
        {"Lviv", "Rovno", TransportType::CAR, "2023-10-15", "23:00", "2023-10-16", "01:00", 15.0, 1},

        // Пути с пятью пересадками
        {"Moscow", "London", TransportType::AIRPLANE, "2023-10-15", "03:00", "2023-10-15", "06:00", 400.0, 1},
        {"London", "Paris", TransportType::TRAIN, "2023-10-15", "07:00", "2023-10-15", "10:00", 100.0, 2},
        {"Paris", "Berlin", TransportType::TRAIN, "2023-10-15", "11:00", "2023-10-15", "15:00", 80.0, 1},
        {"Berlin", "Warsaw", TransportType::TRAIN, "2023-10-15", "16:00", "2023-10-15", "20:00", 50.0, 1},
        {"Warsaw", "Lviv", TransportType::CAR, "2023-10-15", "21:00", "2023-10-16", "01:00", 30.0, 1},
        {"Lviv", "Rovno", TransportType::CAR, "2023-10-16", "02:00", "2023-10-16", "04:00", 15.0, 1},


        // Пути, которые никуда не ведут
       {"Moscow", "Nowhere", TransportType::AIRPLANE, "2023-10-15", "10:00", "2023-10-15", "12:00", 200.0, 1},
       {"Kyiv", "Unknown", TransportType::CAR, "2023-10-15", "15:00", "2023-10-15", "18:00", 25.0, 2},
       {"Rovno", "Limbo", TransportType::TRAIN, "2023-10-15", "20:00", "2023-10-15", "22:00", 10.0, 1}
    };

    return list;
}