# Write your MySQL query statement below
select p.product_id, COALESCE(
        ROUND(SUM(p.price * u.units) / SUM(u.units), 2),
        0
    ) as average_price
from Prices p
left join UnitsSold u
on u.product_id = p.product_id
and u.purchase_date between p.start_date and p.end_date
group by product_id