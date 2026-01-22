# Write your MySQL query statement below
select id from Weather w1 where w1.temperature > (select w2.temperature from Weather w2 where w2.recordDate=DATE_SUB(w1.recordDate, INTERVAL 1 DAY))