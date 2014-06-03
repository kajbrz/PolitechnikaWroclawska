using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


using DominoGame;

using SFML.Audio;
using SFML.Graphics;
using SFML.Window;


namespace CSharpDominoSFML
{
    class Program
    {
        static InterfaceDomino GameDomino;
        static int HeightWindow = 600;
        static int WidthWindow = 800;
        static MySFML.MyButton left;
        static MySFML.MyButton right;
        static MySFML.MyButton draw;
        static MySFML.MyButton restart;
        static MySFML.RenderAllDominos renderalldominos;

        static String path_ImageBlockDomino;
        static String path_Font;
        static String path_image_button;
        static Texture windowcapture;
        static List<Vector2f> dominosposition;
        static int INDEX = -1;
        //MAIN()

        
        static void Main(string[] args)
        {
            dominosposition = new List<Vector2f>();
            GameDomino = new Domino_NormalRules();
            GameDomino.start_game();

            dominoAi.DominoAI DominoAi = new dominoAi.DominoAI();
            DominoAi.set_game(GameDomino);

            renderalldominos = new MySFML.RenderAllDominos();

            path_ImageBlockDomino = "resources/blockdomino.png";
            if (!File.Exists(path_ImageBlockDomino))
            {
                Console.WriteLine("ImageBlockDomino not founded");
                return;
            }
            renderalldominos.set_image(new Image(path_ImageBlockDomino));

            String path_ImageBackground = "resources/background.png";
            if (!File.Exists(path_ImageBackground))
            {
                Console.WriteLine("background not founded");
                return;
            }
            Image imagebackground = new Image(path_ImageBackground);
            Texture texturebackground = new Texture(imagebackground);
            texturebackground.Repeated = true;
            Sprite background = new Sprite(texturebackground, new IntRect(0,0,(int)WidthWindow, (int)HeightWindow));

            String path_icon = "resources/icon.png";
            if (!File.Exists(path_icon))
            {
                Console.WriteLine("path_icon not founded");
                return;
            }
            Image image_icon = new Image(path_icon);

            path_Font = "resources/font.ttf";
            if (!File.Exists(path_Font))
            {
                Console.WriteLine("Font not founded");
                return;
            }
            Text score = new Text("Dupa", new Font(path_Font));

             path_image_button = "resources/button151x54.png";
            if (!File.Exists(path_image_button))
            {
                Console.WriteLine("Image button not founded");
                return;
            }
            //left BUTTON
            left = new MySFML.MyButton();
            left.load_image(new Image(path_image_button), "left side", new Font(path_Font));
            left.set_position(new Vector2f(WidthWindow - 200, 350));

            //right BUTTON
            right = new MySFML.MyButton();
            right.load_image(new Image(path_image_button), "right side", new Font(path_Font));
            right.set_position(new Vector2f(WidthWindow - 200, 404));

            //draw BUTTON
            draw = new MySFML.MyButton();
            draw.load_image(new Image(path_image_button), "draw domino", new Font(path_Font));
            draw.set_position(new Vector2f(WidthWindow - 200, 458));

            //restart BUTTON
            restart = new MySFML.MyButton();
            restart.load_image(new Image(path_image_button), "restart" , new Font(path_Font));
            restart.set_position(new Vector2f(WidthWindow - 200, 512));



            score.Color = Color.Black;
            score.CharacterSize = 20;
            score.Position += new Vector2f(WidthWindow - 200, 100);

            ContextSettings contextSettings = new ContextSettings();
            contextSettings.DepthBits = 32;

            RenderWindow window = new RenderWindow(new VideoMode((uint)WidthWindow, (uint)HeightWindow), "Domino Game", Styles.Default, contextSettings);
            window.SetVerticalSyncEnabled(true);

            window.SetIcon(32, 32, image_icon.Pixels);

            window.Closed += new EventHandler(closed_action);
            window.KeyPressed += new EventHandler<KeyEventArgs>(key_pressed);
            window.MouseButtonPressed += new EventHandler<MouseButtonEventArgs>(mouse_pressed);
            

            window.SetFramerateLimit(60);
            bool openWindow = new bool();
            openWindow = true;
            windowcapture = new Texture(window.Capture());
            score.Color = Color.White;
            while (window.IsOpen() && openWindow)
            {
                try
                {
                    DominoAi.play();

                }
                catch (Exception e)
                {
                    //break;    
                }

                if (GameDomino.test_game() == -2)
                {
                    openWindow = false;
                };
                window.DispatchEvents();



                //Points and infromation;
                score.DisplayedString = String.Format("Time game left: {0} \nScore Player1: {1}\nScore Player2: {2}",
                    GameDomino.get_global_time_end(),
                    GameDomino.get_points_player1(),
                    GameDomino.get_points_player2());


                
                /////////////Draw a dominos player and computer//////////
                window.Clear(Color.Yellow);
                window.Draw(background);
                draw_player1(window);
                draw_player2(window); 
                draw_onboard(window);

                window.Draw(left.draw());
                window.Draw(right.draw());
                window.Draw(draw.draw());
                window.Draw(restart.draw());
                window.Draw(score);

                window.Display();

                if (openWindow == false)
                {
                    windowcapture = new Texture(window.Capture());
                }

            }
            //window.Close();
            //window = new RenderWindow(new VideoMode((uint)WidthWindow, (uint)HeightWindow), "Domino Game", Styles.Default, contextSettings);
            //window.Closed += new EventHandler(closed_action);
            //window.KeyPressed += new EventHandler<KeyEventArgs>(key_pressed);
            //window.MouseButtonPressed += new EventHandler<MouseButtonEventArgs>(mouse_pressed);



            System.Diagnostics.Stopwatch start = new System.Diagnostics.Stopwatch();
            start.Start();
            Text winner = new Text(GameDomino.Type_Winner().ToString(),new Font(path_Font), 30);
            winner.Color = Color.Red;
            while (window.IsOpen())
            {
                window.DispatchEvents();



               



               
                window.Draw(new Sprite(windowcapture));

                if (start.ElapsedMilliseconds > 100)
                {
                    winner.Position += new Vector2f(1, 4);
                    if(winner.Position.Y > HeightWindow)
                        winner.Position = new Vector2f(-1, -4);
                }


                window.Draw(winner);
                window.Display();
            }


        }

        static void closed_action(object Sender, EventArgs e)
        {
            RenderWindow closed = (RenderWindow)Sender;
            closed.Close();            
        }
        static void key_pressed(object Sender, KeyEventArgs e)
        {
            RenderWindow closed = (RenderWindow)Sender;
            if (e.Code == Keyboard.Key.Escape)
                closed.Close();
        }
        static void mouse_keep(object Sender, MouseButtonEventArgs e)
        {

        }
        static void mouse_pressed(object Sender, MouseButtonEventArgs e)
        {
            RenderWindow closed = (RenderWindow)Sender;
            if (e.Button == Mouse.Button.Left)
            {
                Text text = new Text();
                text.DisplayedString = "Co się dzieje?";
                text.Color = Color.Black;
                text.CharacterSize = 20;
                closed.Draw(text);     
            }
            Vector2f mouse = new Vector2f(e.X, e.Y);
            if (left.isClicked(mouse))
            {
                if (INDEX != -1)
                    Console.WriteLine(GameDomino.send_block(INDEX, 0, 0));
            }
            if (right.isClicked(mouse))
            {
                if (INDEX != -1)
                    Console.WriteLine(GameDomino.send_block(INDEX, 1,0 ));                    
            }
            if (draw.isClicked(mouse))
            {
                GameDomino.draw_domino(0);
            }
            if (restart.isClicked(mouse))
            {
                GameDomino.stop_game();
                GameDomino.start_game();
            }

            check_choose_domino(
                new Vector2f(closed.InternalGetMousePosition().X,
                closed.InternalGetMousePosition().Y),
                dominosposition,new Vector2f(renderalldominos.getSizeImage().X,
                renderalldominos.getSizeImage().Y));
            
        }
        static void draw_onboard(RenderWindow window)
        {
            int n = GameDomino.get_list_of_blockdomino_onboard().Count;

            int count_x_position = 0;
            for (int i = 0; i < n; i++)
            {
                Sprite sprite = renderalldominos.get_the_sprite(
                    GameDomino.get_list_of_blockdomino_onboard()[i].Value_Up,
                    GameDomino.get_list_of_blockdomino_onboard()[i].Value_Down);
                rotate rotate = GameDomino.get_list_of_blockdomino_onboard()[i].Rotate;

                sprite.Position = new Vector2f(count_x_position, 100);
                
                if (i == 0)
                    Console.WriteLine(rotate);

                switch (rotate)
                {
                    case rotate.horizonta_left:
                        {
                            sprite.Rotation = 270;
                            sprite.Position += new Vector2f(0, renderalldominos.getSizeImage().X);
                            count_x_position += (int)renderalldominos.getSizeImage().Y;
                            break;
                        }
                    case rotate.horizontal_right:
                        {
                            sprite.Rotation = 90;
                            sprite.Position += new Vector2f(renderalldominos.getSizeImage().Y, 0);
                            count_x_position += (int)renderalldominos.getSizeImage().Y;
                            break;
                        }
                    case rotate.vertical:
                        {
                            count_x_position += (int)renderalldominos.getSizeImage().X;
                            break;
                        }
                }

                window.Draw(sprite);
            }
        }


        static void draw_player2(RenderWindow window)
        {
            int n = GameDomino.get_list_of_blockdomino_player2().Count;
            for (int i = 0; i < n; i++)
            {
                Sprite sprite = renderalldominos.get_the_sprite(0,0);

                sprite.Position = new Vector2f(-100 + i * renderalldominos.getSizeImage().X + (WidthWindow/2) - (n / 2) * renderalldominos.getSizeImage().X, 0);
                window.Draw(sprite);
            }
        }


        static void draw_player1(RenderWindow window)
        {
            int n = GameDomino.get_list_of_blockdomino_player1().Count;
            List<Vector2f> temporary = new List<Vector2f>();
            for (int i = 0; i < n ; i++)
            {
                Sprite sprite = renderalldominos.get_the_sprite(
                    GameDomino.get_list_of_blockdomino_player1()[i].Value_Up,
                    GameDomino.get_list_of_blockdomino_player1()[i].Value_Down);

                sprite.Rotation = 0;
                sprite.Position = new Vector2f(-100 + i * renderalldominos.getSizeImage().X + (WidthWindow / 2) - (n / 2) * renderalldominos.getSizeImage().X, HeightWindow - renderalldominos.getSizeImage().Y);
                if (INDEX == i)
                    sprite.Position += new Vector2f(0, -10);
                temporary.Add(sprite.Position);
                
                window.Draw(sprite);
            }
            dominosposition.Clear();
            dominosposition.AddRange(temporary.AsEnumerable());
            
        }

        public static void check_choose_domino(Vector2f mouse_position, List<Vector2f> positions, Vector2f sizedomino)
        {
            Vector2f temp = new Vector2f(0,0);
            for (int i = 0; i < positions.Count; i++)
            {
                temp = positions[i] + sizedomino;
                if (mouse_position.X > positions[i].X
                    && mouse_position.Y > positions[i].Y
                    && mouse_position.X < temp.X
                    && mouse_position.Y < temp.Y)
                {
                    if (INDEX == -1)
                    {
                        INDEX = i;
                    }
                    else
                        INDEX = -1;
                    break;
                }

            }
        }
        public static void console_output()
        {
            Console.WriteLine("\nJackpot: ");
            foreach (BlockDomino bd in GameDomino.get_list_of_blockdomino_jackpot())
            {
                Console.Write("[{0}:{1}]", bd.Value_Up, bd.Value_Down);
            }
            Console.WriteLine("\nPlayer1: ");
            foreach (BlockDomino bd in GameDomino.get_list_of_blockdomino_player1())
            {
                Console.Write("[{0}:{1}]", bd.Value_Up, bd.Value_Down);
            }
            Console.WriteLine("\nPlayer2: ");
            foreach (BlockDomino bd in GameDomino.get_list_of_blockdomino_player2())
            {
                Console.Write("[{0}:{1}]", bd.Value_Up, bd.Value_Down);
            }
            Console.WriteLine("\nOnBoard: ");
            foreach (BlockDomino bd in GameDomino.get_list_of_blockdomino_onboard())
            {
                switch (bd.Rotate)
                {
                    case rotate.horizonta_left:
                        {
                            Console.Write("[{0}:{1}]", bd.Value_Up, bd.Value_Down);
                            break;
                        }
                    case rotate.horizontal_right:
                        {
                            Console.Write("[{1}:{0}]", bd.Value_Up, bd.Value_Down);
                            break;
                        }
                    case rotate.vertical:
                        {
                            Console.Write("[{0}]", bd.Value_Up);
                            break;
                        }


                }

            }




        }

    }
}
