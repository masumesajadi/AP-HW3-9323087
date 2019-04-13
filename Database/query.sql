--Q1
select * from t_user where phone = '09120000001';

--Q2
update t_user
set email = 'apstudent2019@gmail.com'
where phone = '09120000001';

--Q3
select channel.title from channel,channelMembership,t_user where t_user.phone = '09120000003' and
                                                                t_user.telegram_id = channelMembership.user_id and
                                                                channelMembership.channel_id = channel.telegram_id;

--Q4
select count(*)
from channelMembership
where channelMembership.channel_id = 'aut_ap_2019';

--Q5
select email from t_user where phone like '0935%';

--Q6
select phone from t_user where t_user.id in(select blocked_user_id from t_user,BlockUser where t_user.phone = '09120000001' and 
                                                t_user.id = BlockUser.blocker_user_id and
                                                now() - BlockUser.created_at < interval '1 month'); 

--Q7
select email from t_user,channel where channel.creator_id = t_user.id 
and t_user.email = 'apstudent2019@gmail.com'
and channel.id in(
    select channel_id from channelMembership  
    group by channel_id
    having count(*) > 3);

--Q8
select message_text from Message where sender_id = 'amir.jahanshahi' and receiver_id = 'sHDiV4RHs' OR
                                        sender_id = 'sHDiV4RHs' and receiver_id = 'amir.jahanshahi';


delete from MESSAGE where sender_id = 'amir.jahanshahi' and receiver_id = 'sHDiV4RHs' OR
                        sender_id = 'sHDiV4RHs' and receiver_id = 'amir.jahanshahi';

--Q9
select phone from t_user where telegram_id in (
    select creator_id from Channel where channel.id IN (
        select id from ChannelMessage
        group by id
        having now() - max(created_at) > INTERVAL '1' MONTH
    )
);
