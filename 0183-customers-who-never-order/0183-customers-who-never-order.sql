# Write your MySQL query statement below
select cust.name Customers from customers cust
left join Orders o on cust.id = o.customerid
where o.customerId is NULL