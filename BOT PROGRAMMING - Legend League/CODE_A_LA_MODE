import sys
import math

CHOPPED_STRAWBERRIES = "CHOPPED_STRAWBERRIES"
STRAWBERRIES = "STRAWBERRIES"
NONE = "NONE"
BLUEBERRIES = "BLUEBERRIES"
DISH = "DISH"
ICE_CREAM = "ICE_CREAM"
CHOPPING_BOARD = "CHOPPING_BOARD"
OVEN = "OVEN"
DOUGH = "DOUGH"
CROISSANT = "CROISSANT"
CHOPPED_DOUGH = "CHOPPED_DOUGH"
RAW_TART = "RAW_TART"
TART = "TART"
WINDOW = "WINDOW"

text_counter = 0
lyrics = [
    '♫ Never gonna',
    'give you up',
    'let you down',
    'run around',
    'and desert you',
    '♫ Never gonna',
    'make you cry',
    'say goodbye',
    'tell a lie',
    'and hurt you',
    '♫ ♪ ♫ ♪'
]

insults = [
    'My gran could do better', 'And she\'s dead!', '♪ ☺',
    'What are you?', 'An idiot sandwich?', '♪ ☺',
    'I wish you\'d jump', 'in the oven', 'That would make my life', 'A lot easier!', '♪ ☺',
    'Congratulations..', 'on the worst dish', 'in this competition', 'so far!', '♪ ☺'
]


def print_err(string):
    print(string, file=sys.stderr)


print_debug_messages = True


def print_debug(string):
    if print_debug_messages:
        print("DEBUG: %s" % string, file=sys.stderr)


def get_distance(a_pos, b_pos):
    xa, ya = list(map(int, a_pos.split(" ")))
    xb, yb = list(map(int, b_pos.split(" ")))

    distance = math.sqrt(((xa - xb) ** 2) + ((ya - yb) ** 2))
    return distance


# =======================

class Action:
    @staticmethod
    def follow_partner(coords):
        tx, ty = list(map(int, coords.split(" ")))
        print_debug("Test1 %d %d %d" % (myChef.x, partnerChef.x, tx))
        if myChef.x <= partnerChef.x <= tx:
            if myChef.y <= partnerChef.y <= ty:
                return "MOVE " + partnerChef.str_coords

        if myChef.x >= partnerChef.x >= tx:
            if myChef.y >= partnerChef.y >= ty:
                return "MOVE " + partnerChef.str_coords
        return None

    @staticmethod
    def use(target):
        follow_partner = False
        if follow_partner:
            follow_command = Action.follow_partner(Kitchen.get_coords(target))
            if follow_command is not None:
                return follow_command

        return "USE " + Kitchen.get_coords(target)

    @staticmethod
    def use_coords(p_x, p_y):
        follow_partner = False
        if follow_partner:
            follow_command = Action.follow_partner("%d %d" % (p_x, p_y))
            if follow_command is not None:
                return follow_command

        return "USE %d %d" % (int(p_x), int(p_y))

    @staticmethod
    def move(target):
        return "MOVE " + Kitchen.get_coords(target)


class Chef:
    def __init__(self, name, p_x, p_y, items):
        self.name = name
        self.x = int(p_x)
        self.y = int(p_y)
        self.item = items.split("-")
        self.action_state = None
        self.waiting_bake = False
        self.str_coords = ""
        self.update_str_coords()
        self.target_command = ""
        self.repeated_cmds = 0

    def update_info(self, p_x, p_y, items):
        self.x = int(p_x)
        self.y = int(p_y)
        self.update_str_coords()
        self.item = items.split("-")

    def update_str_coords(self):
        self.str_coords = "%d %d" % (self.x, self.y)

    def show_items(self):
        print_err(self.name + " : " + " & ".join(self.item))

    def has_all_items(self):
        ready = True
        for it in self.target_command:
            if it not in self.item:
                ready = False

        return ready

    def is_around_coords(self, p_x, p_y):
        p_x = int(p_x)
        p_y = int(p_y)
        if p_x >= self.x - 1 and p_x <= self.x + 1:
            if p_y >= self.y - 1 and p_y <= self.y + 1:
                return True
        return False

    def is_around(self, target, direction=None, empty=None):

        search_range_x = range(-1, 2)
        search_range_y = range(-1, 2)

        if len(target) > 1:
            target = Kitchen.get_initial(target)

        if direction is not None:
            p_x, p_y = Kitchen.get_coords(direction).split(" ")
            p_x = int(p_x)
            p_y = int(p_y)
            if p_x <= self.x:
                search_range_x = range(1, -2, -1)
            if p_y >= self.y:
                search_range_y = range(1, -2, -1)

        for iy in search_range_y:
            for ix in search_range_x:
                look_x = self.x + ix
                look_y = self.y + iy
                if Kitchen.map[look_y][look_x] == target:
                    if empty is None:
                        return [look_x, look_y]
                    else:
                        if TableItem.get_item_at_coords(look_x, look_y) is None:
                            return [look_x, look_y]
        return None

    def bake_it(self, ingr, result):
        self.waiting_bake = True
        if (ingr in oven_contents or (
                result in oven_contents and oven_timer >= 4)) and NONE in self.item and not partnerChef.is_around(OVEN):
            if process_comp_dish is not None:
                return Action.use_coords(process_comp_dish.x, process_comp_dish.y)
            else:
                return Action.use(DISH)
        else:
            return Action.use(OVEN)

    def use_dish(self):
        possiblity1 = "99 99"
        if TableItem.has_item(DISH):
            possiblity1 = TableItem.get_item_coords(DISH)
        possiblity2 = Kitchen.get_coords(DISH)

        if get_distance(self.str_coords, possiblity1) < get_distance(self.str_coords, possiblity2):
            return "USE " + possiblity1
        else:
            return "USE " + possiblity2

    def drop_dish(self):
        search_table = self.is_around("#", empty=True)
        if search_table is not None:
            p_x, p_y = list(map(int, search_table))
            return Action.use_coords(p_x, p_y)
        return None


class Kitchen:
    map = []

    @staticmethod
    def add_line_to_map(line):
        Kitchen.map.append(list(line))

    @staticmethod
    def show_map():
        for line in Kitchen.map:
            print_err("-".join(str(p_x) for p_x in line))

    @staticmethod
    def get_coords(target):
        real_target = target
        if len(target) > 1:
            real_target = Kitchen.get_initial(target)

        for index, line in enumerate(Kitchen.map):
            if real_target in line:
                coords = "%d %d" % (line.index(real_target), index)
                return coords
        return "COORDS_NOT_FOUND (%s / %s)" % (target, real_target)

    @staticmethod
    def get_initial(p_item):
        values = {
            DISH: "D",
            ICE_CREAM: "I",
            BLUEBERRIES: "B",
            STRAWBERRIES: "S",
            CHOPPING_BOARD: "C",
            OVEN: "O",
            DOUGH: "H",
            WINDOW: "W"
        }

        if p_item in values:
            return values[p_item]
        else:
            return "NO INITIAL FOUND"


class Customer:
    nb_customers = 0
    full_list = []
    waiting_list = []

    def __init__(self, items, award):
        self.item = items.split("-")  # customer_item: the food the customer is waiting for
        self.award = award  # customer_award: the number of points awarded for delivering the food
        self.id = Customer.nb_customers
        Customer.nb_customers += 1

        if TART in self.item or CROISSANT in self.item or CHOPPED_STRAWBERRIES in self.item:
            new_item = []
            for ingr in [TART, CROISSANT, CHOPPED_STRAWBERRIES]:
                if TART in self.item:
                    self.item.remove(ingr)
                    new_item.append(ingr)

            for it in self.item:
                new_item.append(it)

            for ingr in [CHOPPED_STRAWBERRIES, CROISSANT, TART]:
                if ingr in new_item and TableItem.has_item(ingr):
                    new_item.remove(ingr)
                    new_item.insert(0, ingr)

            self.item = new_item

    @staticmethod
    def show_all_customers():
        for cus in Customer.full_list:
            print_err("(%d) item:%s / award:%d" % (cus.id, "-".join(cus.item), cus.award))
            # (1) item:DISH-BLUEBERRIES-ICE_CREAM / award:650

    @staticmethod
    def show_waiting_customers():
        for cus in Customer.waiting_list:
            print_err("(%d) item:%s / award:%d" % (cus.id, "-".join(cus.item), cus.award))
            # (1) item:DISH-BLUEBERRIES-ICE_CREAM / award:650

    @staticmethod
    def get_best_order_item():
        best_item = None
        award = 0
        nb_actions = 99
        print_debug("remaining turns : %d" % turns_remaining)
        for cus in Customer.waiting_list:
            action_weight = 0
            nb_items = len(cus.item) - 1  # -1 pour le DISH

            if TART in cus.item:
                if TableItem.has_item(TART):
                    action_weight += 2
                else:
                    action_weight += 8
            if CROISSANT in cus.item:
                if TableItem.has_item(CROISSANT):
                    action_weight += 2
                else:
                    action_weight += 6
            if CHOPPED_STRAWBERRIES in cus.item and not TableItem.has_item(CHOPPED_STRAWBERRIES):
                if TableItem.has_item(CHOPPED_STRAWBERRIES):
                    action_weight += 2
                else:
                    action_weight += 3
            if ICE_CREAM in cus.item:
                action_weight += 1
            if BLUEBERRIES in cus.item:
                action_weight += 1

            relative_award = round(cus.award / action_weight, 2)
            # print_debug("Relative award : %f" % relative_award)

            # SELECTION DU MEILLEUR

            # print_debug("Command : " + str(cus.item))
            # print_debug("Award : " + str(relative_award))
            # print_debug("Weight : " + str(action_weight))
            # print_debug(# =======")

            if turns_remaining < 80:
                if action_weight < nb_actions:
                    nb_actions = action_weight
                    best_item = cus.item
            else:
                if relative_award > award:
                    award = relative_award
                    best_item = cus.item

        return best_item


class TableItem:
    list = []

    def __init__(self, p_x, p_y, items):
        self.x = int(p_x)
        self.y = int(p_y)
        self.item = items.split("-")

    @staticmethod
    def show_all_items():
        for index, it in enumerate(TableItem.list):
            print_err("%d - %s %s %s" % (index, it.x, it.y, it.item))

    def item_is_ordered(self, customers):
        for cus in customers:
            if cus.item[1] in self.item and cus.item[2] in self.item:
                coords = "%d %d" % (self.x, self.y)
                return coords

    @staticmethod
    def get_item_at_coords(p_x, p_y):
        for it in TableItem.list:
            if it.x == int(p_x) and it.y == int(p_y):
                return it.item
        return None

    @staticmethod
    def has_item(p_item):
        for it in TableItem.list:
            # print_debug("Has Item Comp : %s / %s" % (item, it.item))
            if p_item in it.item and len(it.item) == 1:
                return True
        return False

    @staticmethod
    def get_item_coords(p_item):
        for it in TableItem.list:
            if p_item in it.item:
                return [it.x, it.y]
        return "NO ITEM FOUND (%s)" % p_item

    @staticmethod
    def get_all_dishes():
        for it in TableItem.list:
            if DISH in it.item:
                print_debug("GetAll : %s : comp=%s" % (
                    " & ".join(it.item), str(TableItem.dish_is_compatible(it.item, myChef.target_command))))

    @staticmethod
    def dish_is_compatible(target_items, order_items, except_item=None):
        if len(target_items) > len(order_items):
            # print_debug("Too many items in target_items!")
            return False

        if target_items is None:
            # print_debug("Dish comp - target_items = None!")
            return False

        if order_items is None:
            # print_debug("Dish comp - order_items = None!")
            return False

        if DISH not in target_items:
            # print_debug("No dish in target_items!")
            return False

        if except_item is not None and except_item in target_items:
            # print_debug("Except_item in target_items!")
            return False

        for it in target_items:
            if it not in order_items:
                # print_debug("%s in target not in order!" % it)
                return False

        return True

    @staticmethod
    def find_most_compatible_dish(items, except_item=None):
        nb_items = 0
        return_dish = None
        for it in TableItem.list:
            if DISH in it.item and TableItem.dish_is_compatible(it.item, items, except_item):
                if len(it.item) > nb_items:
                    nb_items = len(it.item)
                    return_dish = it
        return return_dish


# ============== INIT ============================

show_waiting = False
show_table_items = False
show_active_order = True
show_oven = False

num_all_customers = int(input())
for i in range(num_all_customers):
    customer_item, customer_award = input().split()
    customer_award = int(customer_award)
    newCustomer = Customer(customer_item, customer_award)
    Customer.full_list.append(newCustomer)

# Customer.show_all_customers()

for i in range(7):
    Kitchen.add_line_to_map(input())

Kitchen.show_map()

myChef = Chef("My Chef", 99, 99, "")
partnerChef = Chef("My Partner", 99, 99, "")
old_action = ['', '']

# game loop
while True:
    turns_remaining = int(input())

    player_x, player_y, player_item = input().split()
    myChef.update_info(player_x, player_y, player_item)
    partner_x, partner_y, partner_item = input().split()
    partnerChef.update_info(partner_x, partner_y, partner_item)

    num_tables_with_items = int(input())  # the number of tables in the kitchen that currently hold an item
    TableItem.list = []
    for i in range(num_tables_with_items):
        table_x, table_y, item = input().split()
        newItem = TableItem(table_x, table_y, item)
        TableItem.list.append(newItem)

    if show_table_items:
        print_err("Items:")
        TableItem.show_all_items()

    # oven_contents: ignore until wood 1 league
    oven_contents, oven_timer = input().split()
    oven_timer = int(oven_timer)
    oven_contents = oven_contents.split("-")

    num_customers = int(input())  # the number of customers currently waiting for food
    Customer.waiting_list = []
    for i in range(num_customers):
        customer_item, customer_award = input().split()
        customer_award = int(customer_award)
        newCustomer = Customer(customer_item, customer_award)
        Customer.waiting_list.append(newCustomer)

    # ====== INFO MESSAGES ==============================

    if show_waiting:
        print_err("Waiting:")
        Customer.show_waiting_customers()

    if show_oven:
        print_err("Oven (%d):" % oven_timer)
        print_err(oven_contents)

    if show_table_items:
        TableItem.get_all_dishes()

    myChef.show_items()

    # ====== LOGIC ==============================

    next_action = "WAIT"

    if myChef.action_state is None:
        if myChef.target_command is not None:
            my_order_still_available = False
            for ord in Customer.waiting_list:
                # print_debug(myChef.target_command)
                # print_debug(ord.item)
                # print_debug(TableItem.dish_is_compatible(myChef.target_command, ord.item))
                if TableItem.dish_is_compatible(myChef.target_command, ord.item):
                    myChef.target_command = ord.item
                    my_order_still_available = True

            if not my_order_still_available:
                myChef.target_command = None

            if myChef.target_command is None:
                myChef.target_command = Customer.get_best_order_item()

    if show_active_order:
        print_err("My Active Order: %s" % ("-".join(myChef.target_command)))

    if not myChef.has_all_items():

        comp_dish = TableItem.find_most_compatible_dish(myChef.target_command)
        can_drop = myChef.drop_dish()
        # print_debug("My Dish comp? %s" % str(TableItem.dish_is_compatible(myChef.item, myChef.target_command)))

        if myChef.action_state is None:
            # print_err("Action : NONE")

            if DISH not in myChef.item and comp_dish is not None and len(myChef.item) < len(comp_dish.item):
                print_err("Found comp dish! :)")
                next_action = Action.use_coords(comp_dish.x, comp_dish.y)

            elif NONE not in myChef.item and not TableItem.dish_is_compatible(myChef.item,
                                                                              myChef.target_command) and can_drop:
                print_err("Action : Not compatible! Dropping dish...")
                next_action = can_drop

            elif DISH in myChef.item and comp_dish is not None and len(comp_dish.item) > len(myChef.item):
                print_err("Part Compatible dish")
                if can_drop is not None:
                    next_action = can_drop
            else:
                # print_debug("Part Other")
                processed_foods = [TART, CROISSANT, CHOPPED_STRAWBERRIES]

                for order_part in myChef.target_command:
                    # print_debug("Order : " + order_part)

                    if order_part not in myChef.item:
                        # print_debug("Go! : " + order_part)

                        if order_part not in processed_foods:

                            # print_debug("%s : Standard food" % order_part)
                            if NONE in myChef.item:
                                if comp_dish is not None:
                                    next_action = Action.use_coords(comp_dish.x, comp_dish.y)
                                else:
                                    next_action = Action.use(DISH)
                            else:
                                next_action = Action.use(order_part)
                        else:
                            # print_debug("%s : Processed" % order_part)
                            if TableItem.has_item(order_part):
                                x, y = list(map(int, TableItem.get_item_coords(order_part)))
                                if DISH in TableItem.get_item_at_coords(x, y):
                                    if can_drop is not None:
                                        next_action = can_drop
                                else:
                                    next_action = Action.use_coords(x, y)
                            else:
                                # ============ PROCESS =========================
                                myChef.action_state = "process_" + order_part
                                break
                                # ==============================================
        else:
            # print_err("Action : %s!" % myChef.action_state)

            if myChef.action_state == "process_" + TART:
                # ================ PROCESSING TART ==================
                process_comp_dish = TableItem.find_most_compatible_dish(myChef.target_command, TART)

                if DISH in myChef.item and TART not in myChef.item and can_drop is not None and not myChef.waiting_bake:
                    next_action = can_drop
                elif DOUGH in myChef.item:
                    next_action = Action.use(CHOPPING_BOARD)
                elif CHOPPED_DOUGH in myChef.item:
                    next_action = Action.use(BLUEBERRIES)
                elif (
                        RAW_TART in myChef.item or RAW_TART in oven_contents or TART in oven_contents) and TART not in myChef.item:
                    if RAW_TART in myChef.item:
                        if TART in oven_contents or (
                                RAW_TART in oven_contents and oven_timer < 3 and not partnerChef.is_around(OVEN)):
                            next_action = can_drop
                        else:
                            next_action = Action.use(OVEN)
                    else:
                        next_action = myChef.bake_it(RAW_TART, TART)
                elif TART in myChef.item:
                    myChef.waiting_bake = False
                    if DISH not in myChef.item:
                        if process_comp_dish is not None:
                            next_action = Action.use_coords(process_comp_dish.x, process_comp_dish.y)
                            if myChef.is_around_coords(process_comp_dish.x, process_comp_dish.y):
                                myChef.action_state = None
                        else:
                            next_action = Action.use(DISH)
                            if myChef.is_around(DISH) != None:
                                myChef.action_state = None
                    else:
                        myChef.action_state = None
                else:
                    for ingr in [TART, RAW_TART, CHOPPED_DOUGH, DOUGH]:
                        if TableItem.has_item(ingr):
                            x, y = list(map(int, TableItem.get_item_coords(ingr)))
                            if DISH not in TableItem.get_item_at_coords(x, y):
                                next_action = Action.use_coords(x, y)
                                break
                        else:
                            next_action = Action.use(DOUGH)

            elif myChef.action_state == "process_" + CROISSANT:
                # ================ PROCESSING CROISSANT ==================
                process_comp_dish = TableItem.find_most_compatible_dish(myChef.target_command, CROISSANT)

                if DISH in myChef.item and CROISSANT not in myChef.item and can_drop is not None and not myChef.waiting_bake:
                    next_action = can_drop
                elif (
                        DOUGH in myChef.item or DOUGH in oven_contents or CROISSANT in oven_contents) and CROISSANT not in myChef.item:
                    if DOUGH in myChef.item:
                        if CROISSANT in oven_contents or (
                                DOUGH in oven_contents and oven_timer < 3 and not partnerChef.is_around(OVEN)):
                            next_action = can_drop
                        else:
                            next_action = Action.use(OVEN)
                    else:
                        next_action = myChef.bake_it(DOUGH, CROISSANT)
                elif CROISSANT in myChef.item:
                    myChef.waiting_bake = False
                    if DISH not in myChef.item:
                        if process_comp_dish is not None:
                            next_action = Action.use_coords(process_comp_dish.x, process_comp_dish.y)
                            if myChef.is_around_coords(process_comp_dish.x, process_comp_dish.y):
                                myChef.action_state = None
                        else:
                            next_action = Action.use(DISH)
                            if myChef.is_around(DISH) != None:
                                myChef.action_state = None
                    else:
                        myChef.action_state = None
                else:
                    for ingr in [CROISSANT, DOUGH]:
                        if TableItem.has_item(ingr):
                            x, y = list(map(int, TableItem.get_item_coords(ingr)))
                            if DISH not in TableItem.get_item_at_coords(x, y):
                                next_action = Action.use_coords(x, y)
                                break
                        else:
                            next_action = Action.use(DOUGH)


            elif myChef.action_state == "process_" + CHOPPED_STRAWBERRIES:
                # ============ PROCESSING CHOPPED STRAWBERRIES ===============
                process_comp_dish = TableItem.find_most_compatible_dish(myChef.target_command, CHOPPED_STRAWBERRIES)

                if DISH in myChef.item and CHOPPED_STRAWBERRIES not in myChef.item and can_drop is not None:
                    next_action = can_drop
                elif STRAWBERRIES in myChef.item:
                    next_action = Action.use(CHOPPING_BOARD)
                elif CHOPPED_STRAWBERRIES in myChef.item and DISH not in myChef.item:
                    if process_comp_dish is not None:
                        next_action = Action.use_coords(process_comp_dish.x, process_comp_dish.y)
                        if myChef.is_around_coords(process_comp_dish.x, process_comp_dish.y):
                            myChef.action_state = None
                    else:
                        next_action = Action.use(DISH)
                        if myChef.is_around(DISH) is not None:
                            myChef.action_state = None
                else:
                    for ingr in [CHOPPED_STRAWBERRIES, STRAWBERRIES]:
                        if TableItem.has_item(ingr):
                            x, y = list(map(int, TableItem.get_item_coords(ingr)))
                            if DISH not in TableItem.get_item_at_coords(x, y):
                                next_action = Action.use_coords(x, y)
                                break
                        else:
                            next_action = Action.use(STRAWBERRIES)

            else:
                next_action = "ERROR IN PROCESSING CHOICE"

    else:
        next_action = Action.use(WINDOW)

    # ========= ACTION ===========================

    if next_action in old_action:
        myChef.repeated_cmds += 1
    else:
        old_action[0] = old_action[1]
        old_action[1] = next_action
        myChef.repeated_cmds = 0

    print_debug(old_action)
    print_debug(myChef.repeated_cmds)

    if myChef.repeated_cmds >= 20:
        print(old_action[0] + "; WTF is this loop...")
    else:
        print(next_action + "; %s" % insults[text_counter])

    text_counter += 1
    if text_counter > len(insults) - 1:
        text_counter = 0
