using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

using SFML.Audio;
using SFML.Graphics;
using SFML.Window;



namespace MySFML
{
    class MyButton
    {

        private Stopwatch time_start;
        private Image button = null;
        private RenderTexture buttons = null;
        private Text text_on_button = null;
        private Font font = null;

        private Sprite[] up_down = null;
        private Vector2f position;
               

        public MyButton() 
        {
            text_on_button = new Text();

            position.X = 0;
            position.Y = 0;

            time_start = new Stopwatch();
            time_start.Start();
        }

        public void set_position(Vector2f position)
        {
            this.position = position;

            for (int i = 0; i < 2; i++)
                up_down[i].Position = position;

        }
        public Sprite draw()
        {

            
            if ((time_start.ElapsedMilliseconds / 100) < 1)
            {
                return up_down[1];
            }
            else
            {
                return up_down[0];
            }
        }


        public bool isClicked(Vector2f mouse_position)
        {

            Vector2f position_right_bottom = new Vector2f(position.X + button.Size.X, position.Y + button.Size.Y / 2);
            if (mouse_position.X > position.X
                && mouse_position.Y > position.Y
                && mouse_position.X < position_right_bottom.X
                && mouse_position.Y < position_right_bottom.Y)
            {

                time_start = Stopwatch.StartNew();
                return true;
            }
            return false;
        }

        public void load_image(Image button, String name, Font font)
        {

            this.button = button;
            text_on_button.DisplayedString = name;
            text_on_button.Font = font;
            text_on_button.CharacterSize = 20;

            generate_texture();
            generate_sprites();

        }

        private void generate_texture()
        {

            buttons = new RenderTexture(button.Size.X, button.Size.Y);
            buttons.Draw(new Sprite(new Texture(button)));

            text_on_button.Position += new Vector2f(10, button.Size.Y / 4 - 10);
            buttons.Draw(text_on_button);

            text_on_button.Position += new Vector2f(5, button.Size.Y / 2 + 3);
            buttons.Draw(text_on_button);

            buttons.Display();
        }
        private void generate_sprites()
        {
            up_down = new Sprite[2];

            up_down[0] = new Sprite(buttons.Texture, new IntRect(
                0, 0, (int)button.Size.X, (int)button.Size.Y/2));

            up_down[1] = new Sprite(buttons.Texture, new IntRect(
                            0, (int)button.Size.Y/2, (int)button.Size.X, (int)button.Size.Y/2));
            
        }
    
    }

    class RenderAllDominos
    {

        private Image image_of_blockdomino = null;
        private RenderTexture points_of_all_blockdomino = null;
        private RenderTexture texture_of_all_blockdomino = null;

        private Sprite[][] sprite_of_every_block;


        public RenderAllDominos() { }

        public RenderTexture getTexture()
        {
            return texture_of_all_blockdomino;
        }

        public void draw_all_domino()
        {
            sprite_of_every_block = new Sprite[7][];
            for(int i=0; i<7; i++)
                sprite_of_every_block[i] = new Sprite[7];


            IntRect intRect = new IntRect();
            intRect.Width = (int)image_of_blockdomino.Size.X;
            intRect.Height = (int)image_of_blockdomino.Size.Y;

            for (int i = 0; i <7; i++)
                for (int j = 0; j <7; j++)
                {                    
                    intRect.Left = (int)image_of_blockdomino.Size.X*j;
                    intRect.Top = (int)image_of_blockdomino.Size.Y*i;

                    sprite_of_every_block[i][j] = new Sprite(texture_of_all_blockdomino.Texture, intRect);
                }
        }
        
        public void set_image(Image image_of_blockdomino)
        {
            this.image_of_blockdomino = image_of_blockdomino;
            renderPoints();
            renderTextures();
            draw_all_domino();
        }

        private Sprite get_point(int point)
        {
            if(point<0 || point >6)
                point = 0;
            IntRect intRect = new IntRect();
            intRect.Left = (int)image_of_blockdomino.Size.X * point;
            intRect.Top = 0;
            intRect.Width = (int)image_of_blockdomino.Size.X;
            intRect.Height = (int)image_of_blockdomino.Size.Y / 2;
            return new Sprite(points_of_all_blockdomino.Texture, intRect);
        }
        public Vector2u getSizeImage()
        {
            return image_of_blockdomino.Size;
        }
        private void renderTextures()
        {
            texture_of_all_blockdomino = new RenderTexture(image_of_blockdomino.Size.X * 7, image_of_blockdomino.Size.Y * 7);
            Texture block_domino = new Texture(image_of_blockdomino);
            block_domino.Repeated = true;
            Sprite newSprite = new Sprite(block_domino, new IntRect(0, 0, (int)image_of_blockdomino.Size.X * 7, (int)image_of_blockdomino.Size.Y * 7));
            texture_of_all_blockdomino.Draw(newSprite);


            //
            for(int i=0 ; i<=6; i++)
                for (int j = 0; j <= 6; j++)
                {
                    Sprite upSprite = get_point(i);
                    upSprite.Position += new Vector2f(image_of_blockdomino.Size.X * j, image_of_blockdomino.Size.Y * i);

                    Sprite downSprite = get_point(j);
                    downSprite.Position += new Vector2f(image_of_blockdomino.Size.X * j, image_of_blockdomino.Size.Y * i + image_of_blockdomino.Size.Y/2);

                    texture_of_all_blockdomino.Draw(upSprite);
                    texture_of_all_blockdomino.Draw(downSprite);
                }

                        
            texture_of_all_blockdomino.Display();
        }

        public Sprite get_the_sprite(int value_up, int value_down)
        {
            return sprite_of_every_block[value_up][value_down];
        }

        void renderPoints()
        {
            points_of_all_blockdomino = new RenderTexture(image_of_blockdomino.Size.X * 7, image_of_blockdomino.Size.Y / 2);
            points_of_all_blockdomino.Clear(Color.Transparent);
            Shape circle = new CircleShape(3);
            //circle.Position = new Vector2f(10, 4);
            circle.FillColor = Color.Black;

            //drawable
            
            {
                for (int i = 1; i < 7; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (i <= 3)
                        {
                            circle.Position = new Vector2f(image_of_blockdomino.Size.X * (i) + image_of_blockdomino.Size.X * j / i + 5, image_of_blockdomino.Size.Y / 4 - 5);
                        }
                        else
                        {
                            if (j < (i / 2))
                            {
                                circle.Position = new Vector2f(image_of_blockdomino.Size.X * (i) + image_of_blockdomino.Size.X * j / i + 7, image_of_blockdomino.Size.Y / 4 - 10);
                            }
                            else
                            {
                                circle.Position = new Vector2f(image_of_blockdomino.Size.X * (i) + image_of_blockdomino.Size.X * (j - 2) / i + 7, image_of_blockdomino.Size.Y / 4);
                            }
                        }
                        points_of_all_blockdomino.Draw(circle);
                    }
                }
            }
            points_of_all_blockdomino.Display();
        }
    }

    // class MyEffect : SFML.Graphics.
}
