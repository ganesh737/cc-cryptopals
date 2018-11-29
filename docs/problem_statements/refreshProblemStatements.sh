#!/bin/bash

# set 1
for i in {1..8}
do
	wget http://cryptopals.com/sets/1/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s1c${i}.html
done

# set 2
for i in {9..16}
do
	wget http://cryptopals.com/sets/2/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s2c${i}.html
done

# set 3
for i in {17..24}
do
	wget http://cryptopals.com/sets/3/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s3c${i}.html
done

# set 4
for i in {25..32}
do
	wget http://cryptopals.com/sets/4/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s4c${i}.html
done

# set 5
for i in {33..40}
do
	wget http://cryptopals.com/sets/5/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s5c${i}.html
done

# set 6
for i in {41..48}
do
	wget http://cryptopals.com/sets/6/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s6c${i}.html
done

# set 7
for i in {49..56}
do
	wget http://cryptopals.com/sets/7/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s7c${i}.html
done

# set 8 --> need to email :(
# for i in {57..64}
# do
# 	wget http://cryptopals.com/sets/1/challenges/${i} -P /home/ubuntu/workspace/xoding/cryptopals/docs/
# 	mv -v /home/ubuntu/workspace/xoding/cryptopals/docs/$i /home/ubuntu/workspace/xoding/cryptopals/docs/s1c${i}.html
# done
