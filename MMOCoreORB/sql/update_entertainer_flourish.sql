-- Old
--update `skills` set skill_commands = 'private_entertainer_novice,musician,dancer,imagedesigner,startDance,stopDance,startMusic,stopMusic,flourish+1,flourish+2,flourish+3,flourish+4,flourish+5,flourish+6,flourish+7,flourish+8,startDance+basic,startDance+rhythmic,startMusic+starwars1,slitherhorn,flourish' where skill_name = 'social_entertainer_novice'

-- New - Convert back to original record
update `skills` set skill_commands = 'private_entertainer_novice,musician,dancer,imagedesigner,startDance,stopDance,startMusic,stopMusic,flourish+1,flourish+2,flourish+3,flourish+4,flourish+5,flourish+6,flourish+7,flourish+8,startDance+basic,startDance+rhythmic,startMusic+starwars1,slitherhorn' where skill_name = 'social_entertainer_novice'