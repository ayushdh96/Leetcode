# Write your MySQL query statement below
#select id from Weather w1 where w1.temperature > (select w2.temperature from Weather w2 where w2.recordDate=DATE_SUB(w1.recordDate, INTERVAL 1 DAY))
SELECT w1.id
FROM Weather w1
JOIN Weather w2
  ON w1.recordDate = w2.recordDate + INTERVAL 1 DAY
WHERE w1.temperature > w2.temperature;