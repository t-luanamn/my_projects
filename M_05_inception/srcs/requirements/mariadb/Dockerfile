FROM debian:bullseye

LABEL "author"="tluanamn"

# Install MariaDB
RUN apt-get update && apt-get install -y \
    mariadb-server \
    curl

# Copy MariaDB custom configuration
COPY ./conf/mariadb.cnf /etc/mysql/mariadb.conf.d/mariadb.cnf
COPY ./tools/init-mariadb.sh /tmp/init-mariadb.sh

RUN chmod +x /tmp/init-mariadb.sh

# HEALTHCHECK --interval=30s --timeout=10s \
#   CMD mysqladmin ping -h localhost -u root -p"${MYSQL_ROOT_PASSWORD}" || exit 1

EXPOSE 3306

ENTRYPOINT ["bash", "/tmp/init-mariadb.sh"]

# Start MariaDB
CMD ["mysqld"]
