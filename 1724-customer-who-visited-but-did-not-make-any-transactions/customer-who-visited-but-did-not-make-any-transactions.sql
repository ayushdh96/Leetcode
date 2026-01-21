# Write your MySQL query statement below
select Visits.customer_id, count(Visits.customer_id)-count(Transactions.transaction_id) as count_no_trans
from Visits
left join
Transactions
on
Transactions.visit_id=Visits.visit_id
group by Visits.customer_id
having count(Visits.customer_id)-count(Transactions.transaction_id)>0