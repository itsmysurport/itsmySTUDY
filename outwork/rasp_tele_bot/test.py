from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
import time
import picamera

TOKEN = '751327134:AAER637xGXY8GtlvZtPeeizNA4T--oWjd9g'

def get_message(bot, update) :
    if update.message.text == '따라하지마'\
    or update.message.text == '따라하지 말라고':
        update.message.reply_text('싫어')
    else:
        update.message.reply_text("따라하기")
        update.message.reply_text(update.message.text)
    
    
def check_id(bot, update):
    try:
        id = update.message.chat.id
        print('Chat ID', id)
        return id
    except:
        id = update.channel_post.chat.id
        return id

def check_nickname(bot, update):
    try:
        nickname = update.message.from_user.first_name
        print('Chat NickName', nickname)
        return nickname
    except:
        nickname = update.channel_post.from_user.first_name
        return nickname

def on_command(bot, update):
    id = check_id(bot, update)
    nickname = check_nickname(bot, update)
    bot.send_message(chat_id=id, text="안녕하십니까, " + nickname + "님, led의 전원을 켜드리겠습니다!\n\n")

def start_command(bot, update):
    id = check_id(bot, update)
    nickname = check_nickname(bot, update)
    bot.send_message(chat_id=id, text="안녕하세요 " + nickname +"! 새로운 챗봇입니다!\n\n")

def alarm_set(bot, update):
    global set_id
    set_id = check_id(bot, update)
    nickname = check_nickname(bot, update)
    bot.send_message(chat_id=set_id, text="이제" + nickname + "님으로 알람이 설정 되었습니다.\n\n")

def test_capture(bot, update):
    global set_id
    bot.send_message(chat_id=set_id, text="정상적으로 작동합니다!\n\n")
    with picamera.PiCamera() as camera:
        camera.start_preview()
        time.sleep(5)
        camera.capture('/home/pi/Desktop/workspace/itsmySTUDY/outwork/rasp_tele_bot')
        camera.stop_preview()

updater = Updater(TOKEN)

updater.dispatcher.add_handler(CommandHandler('start', start_command))
updater.dispatcher.add_handler(CommandHandler('on', on_command))

#real
updater.dispatcher.add_handler(CommandHandler('set', alarm_set))
updater.dispatcher.add_handler(CommandHandler('test', test_capture))

message_handler = MessageHandler(Filters.text, get_message)
updater.dispatcher.add_handler(message_handler)

updater.start_polling(timeout=3, clean=True)
updater.idle()
