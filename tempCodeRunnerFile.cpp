// Add data to the linked list using the insertNewCases function
            int data2023Week1[15] = {20, 10, 15, 5, 8, 25, 18, 0, 5, 12, 10, 22, 14, 2, 0};
            int data2023Week2[15] = {22, 12, 18, 6, 9, 27, 20, 0, 6, 15, 12, 24, 16, 3, 0};
            int data2023Week3[15] = {23, 15, 19, 7, 10, 30, 22, 0, 7, 18, 14, 26, 18, 4, 0};

            weeklyDengueCases.insertNewCases(2023, 1, data2023Week1);
            weeklyDengueCases.insertNewCases(2023, 2, data2023Week2);
            weeklyDengueCases.insertNewCases(2023, 3, data2023Week3);

            // Check for alerts in specific states
            for (int stateIndexToCheck = 0; stateIndexToCheck < 15; stateIndexToCheck++)
            {
                weeklyDengueCases.checkAlerts(stateIndexToCheck);
            }