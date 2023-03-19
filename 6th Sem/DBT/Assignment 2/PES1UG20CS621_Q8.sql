-- Compare the performance of different indexing strategies (e.g., B-tree, hash) on returns table and record the results.
-- HASH INDEX NOT SUPPORTED IN MYSQL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
CREATE index btree_return_date ON returns(return_date);
CREATE index hash_return_date ON returns(return_date) USING HASH;
explain SELECT *
FROM returns use index(btree_return_date)
WHERE return_date between '2023-01-01' and '2023-12-31';
explain SELECT *
FROM returns use index(hash_return_date)
WHERE return_date between '2023-01-01' and '2023-12-31';