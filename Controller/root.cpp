#pragma once

namespace uk { 

    express_tcp_t root() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){
            cli.render( _STRING_ (
                
                :root {
                    --secondary: #0d0d0c;
                    --primary:   #6636fc;
                    --success:   #c0f461;
                    --warning:   orange;
                    --danger:    crimson;
                    --light:     white;
                    --dark:      black;
                    --mute:      #aaa;
                    --none:      transparent
                }

                /*.........................................................................*/

                html {
                    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, "Noto Sans", sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";
                    -webkit-text-size-adjust: 100%; background: var(--light); font-weight: normal; color: var(--dark); line-height: 1.5; font-size: 16px;
                }

                /*.........................................................................*/

                audio, canvas, iframe, img, svg, video { vertical-align: middle; max-width: 100%; height: auto; box-sizing: border-box; }

                * { color: inherit; text-decoration: none !important; transition: all 0.3s ease-in-out; align-content: flex-start; }

                h1,h2,h3,h4,h5,h6,p,hr { margin: 0px; user-select: text; }

                img:not([src]) { visibility: hidden; display: none; }

                body { overflow-x: hidden; margin: 0px; }

                h1,h2,h3 { font-weight: bolder; }

                /*.........................................................................*/

                h1 { font-size: 2.23125rem; line-height: 1.2; }
                h2 { font-size: 1.7rem;     line-height: 1.3; }
                h3 { font-size: 1.5rem;     line-height: 1.4; }
                h4 { font-size: 1.25rem;    line-height: 1.4; }
                h5 { font-size: 16px;       line-height: 1.4; }
                h6 { font-size: 0.875rem;   line-height: 1.4; }

                /*.........................................................................*/

                .uk-yflip { transform: scaleY(-1) !important; }

                .uk-xflip { transform: scaleX(-1) !important; }

                /*.........................................................................*/

                @font-face {
                    font-family: 'Material Symbols Rounded';
                    src: url(./icon.woff2) format('woff2');
                    font-style: normal;
                    font-weight: 400;
                }

                /*.........................................................................*/

                .uk-inline {
                    -webkit-backface-visibility: hidden;
                    vertical-align: middle;
                    display: inline-block;
                    position: relative;
                    max-width: 100%;
                }

                /*.........................................................................*/

                a, .uk-link {
                    color: var(--primary);
                    text-decoration: none;
                    cursor: pointer;
                }

            ));
        });

        return app;
    }

}