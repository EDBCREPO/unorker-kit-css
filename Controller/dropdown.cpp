#pragma once

namespace uk { 

    express_tcp_t dropdown() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            cli.write( _STRING_(

                .uk-dropdown { position: relative; z-index: 1000;  }

                .uk-dropdown:hover>ul, .uk-dropdown>ul:hover {
                    transform: translateX(-120%) translateY(0%);
                    background-color: var(--secondary);
                    padding: 10px; margin: 0px;
                    flex-direction: column;
                    color: var(--light);
                    border-radius: 5px;
                    position: absolute;
                    left:50%; top:-6px;
                    list-style: none;
                    flex-wrap: wrap;
                    display: flex;
                }

                .uk-dropdown>ul { display: none; }

            ));

            for( auto& color : map_t<string_t,string_t>({
                { "primary",   "light" },
                { "secondary", "light" },
                { "success",   "dark"  },
                { "warning",   "light" },
                { "danger",    "light" },
                { "mute",      "dark"  },
                { "light",     "dark"  },
                { "dark",      "light" },
                { "neutral",   "light" }
            }).data() ){
                cli.write( regex::format( _STRING_(
                    .uk-dropdown-${0}:hover>ul, .uk-dropdown-${0}>ul:hover { 
                        background-color: var(--${0});
                        color: var(--${1});
                    }
                ), color.first, color.second ));
            }

        });

        return app;
    }

}