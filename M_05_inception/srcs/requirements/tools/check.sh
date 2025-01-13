#!/bin/bash

export MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
docker exec -it nginx bash -c "echo '127.0.0.1 tluanamn.42.fr' >> /etc/hosts"

set -e

echo ">>> Running connectivity checks..."
docker exec -it nginx ping -c 3 wordpress
docker exec -it wordpress ping -c 3 mariadb

echo ">>> Verifying WordPress setup..."
docker exec -it wordpress ls -la /var/www/html/wp-config.php || echo "wp-config.php not found!"
docker exec -it wordpress ps aux | grep php-fpm

echo ">>> Checking MariaDB setup..."
docker exec -it mariadb mysql -u root -p${MYSQL_ROOT_PASSWORD} -e "SHOW DATABASES;"
docker exec -it mariadb ls -la /var/lib/mysql

echo ">>> Checking NGINX setup..."
docker exec -it nginx nginx -t || echo "NGINX configuration test failed!"
docker exec -it nginx service nginx status || echo "NGINX service not running!"
docker exec -it nginx ping -c 3 tluanamn.42.fr || echo "DNS resolution failed!"
docker exec -it nginx curl -k https://tluanamn.42.fr || echo "NGINX not serving correctly."

echo ">>> Setup checks completed."
