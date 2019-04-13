
create table t_user (id serial primary key 
,telegram_id varchar(30) not null
,phone varchar(15) not null
,email varchar(30) not null
,password varchar(20) not null
,first_name varchar(20) not null
,last_name varchar(25) not null
,verify_code varchar(10)
,pro_pic_url varchar(50)
,created_at timestamp
,updated_at timestamp);

create table channel(
    id integer NOT NULL,
    telegram_id varchar(30) not null,
    title varchar(30) not null,
    info varchar(100),
    creator_id integer not null,
    created_at timestamp,
    updated_at timestamp,
    primary key(id),
    foreign key(creator_id) references t_user 
    );

create table channelMembership(
    user_id INTEGER not null,
    channel_id INTEGER not null,
    created_at timestamp,
    primary key(user_id,channel_id),
    foreign key(channel_id) references channel);

create table BlockUser(
    blocker_user_id INTEGER not null,
    blocked_user_id INTEGER not null,
    created_at timestamp not null,
    primary key(blocked_user_id,blocker_user_id),
    foreign key(blocked_user_id) references t_user,
    foreign key(blocker_user_id) references t_user
);

CREATE TABLE Message (
    id integer NOT NULL,
    sender_id VARCHAR(30) NOT NULL,
    receiver_id VARCHAR(30) NOT NULL,
    message_type VARCHAR(7) NOT NULL,
    message_text VARCHAR(150) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    CHECK (message_type IN('voice', 'video', 'picture', 'text'))
);

CREATE TABLE ChannelMessage (
    id integer NOT NULL,
    channel_id VARCHAR(30) NOT NULL,
    message_type VARCHAR(7) NOT NULL,
    message_text VARCHAR(150) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    CHECK (message_type IN('voice', 'video', 'picture', 'text'))
);

